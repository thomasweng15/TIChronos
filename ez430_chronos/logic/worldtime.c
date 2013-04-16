// worldtime has an adjustable time offset from regular displayed time
// to allow both time in current location and time 
// in another zone to be displayed.

// only allows time in 24 hr format.
// changes hour only, uses sTime elements in display otherwise
// ******************************************
// Include section

// system
#include "project.h"

// driver
#include "ports.h"
#include "display.h"
#include "vti_as.h"
#include "timer.h"

// logic
#include "clock.h"
#include "worldtime.h"
#include "simpliciti.h"
#include "user.h"
#include "string.h"

// ******************************************
// Global Variable section
struct worldtime wWorldtime;

// ******************************************
// Extern section

// ******************************************
// @fn          reset_worldtime
// @brief       Reset / INIT worldtime data.
// @param       none
// @return      none
// ******************************************
void reset_worldtime(void)
{
	// Reset state is not active
	wWorldtime.mode = WORLDTIME_MODE_OFF;
	
	wWorldtime.hour = sTime.hour;
	
	wWorldtime.display = DISPLAY_DEFAULT_VIEW;
	
	// initialize wtable, ascending order
	// how to calculate index?
	wWorldtime.wtable[0] = (u8 *) " NEW YORK ";
	wWorldtime.wtable[1] = (u8 *) " BUENOS A ";
	wWorldtime.wtable[2] = (u8 *) " ST JOHNS ";
	wWorldtime.wtable[3] = (u8 *) " ATLANTIC ";
	wWorldtime.wtable[4] = (u8 *) " REYKJAVIK";
	wWorldtime.wtable[5] = (u8 *) "   LONDON ";
	wWorldtime.wtable[6] = (u8 *) "   PARIS  ";
	wWorldtime.wtable[7] = (u8 *) " ISTANBUL ";
	wWorldtime.wtable[8] = (u8 *) "   DUBAI  ";
	wWorldtime.wtable[9] = (u8 *) "  KARACHI ";
	wWorldtime.wtable[10] = (u8 *) "   DHAKA  ";
	wWorldtime.wtable[11] = (u8 *) "  JAKARTA ";
	wWorldtime.wtable[12] = (u8 *) "  BEIJING ";
	wWorldtime.wtable[13] = (u8 *) "   TOKYO  ";
	wWorldtime.wtable[14] = (u8 *) "   SYDNEY ";
	wWorldtime.wtable[15] = (u8 *) "  PACIFIC ";
	wWorldtime.wtable[16] = (u8 *) " AUCKLAND ";
	wWorldtime.wtable[17] = (u8 *) "  PACIFIC ";
	wWorldtime.wtable[18] = (u8 *) " HONOLULU ";
	wWorldtime.wtable[19] = (u8 *) "  PACIFIC ";
	wWorldtime.wtable[20] = (u8 *) " ANCHORAGE";
	wWorldtime.wtable[21] = (u8 *) "  SEATTLE ";
	wWorldtime.wtable[22] = (u8 *) "  DENVER  ";             
	wWorldtime.wtable[23] = (u8 *) "  CHICAGO "; 
	
	// use array that stores locations and set to new york
	strcpy((char *) wWorldtime.loc, (char *) wWorldtime.wtable[0]);
}

// ******************************************
// @fn          sx_worldtime
// @brief       set worldtime view.
// @param       u8 line	LINE2 
// @return      none
// ******************************************
void sx_worldtime(u8 line)
{
	// Toggle display items
	if (wWorldtime.display == DISPLAY_DEFAULT_VIEW) {
		
		wWorldtime.display = DISPLAY_ALTERNATIVE_VIEW;
		
	} else {									
		
		wWorldtime.display = DISPLAY_DEFAULT_VIEW;
		
	}
}

// ******************************************
// @fn          mx_worldtime
// @brief       set hour of worldtime.
// @param       u8 line	LINE1, LINE2
// @return      none
// ******************************************
void mx_worldtime(u8 line)
{
	s32 hours;
	u8 * str;
	
	// Clear display
	clear_display_all();

	// Keep global value in case new value is discarded
	hours = wWorldtime.hour;
	
	// Display HH:MM (LINE1) 
	str = itoa(hours, 2, 0);
	display_chars(LCD_SEG_L2_3_2, str, SEG_ON);
	display_symbol(LCD_SEG_L2_COL1, SEG_ON); 
	
	str = itoa(sTime.minute, 2, 0);
	display_chars(LCD_SEG_L2_1_0, str, SEG_ON);
	
	// Loop values until all are set or user breaks	set
	while(1) 
	{
		// Idle timeout: exit without saving 
		if (sys.flag.idle_timeout) break;
		
		// STAR (short): save, then exit 
		if (button.flag.star) 
		{
			// Store local variable in global worldtime
			wWorldtime.hour = hours;
			// Set display update flag
			display.flag.line2_full_update = 1;
			break;
		}	
		
		// Set hour
        set_value(&hours, 2, 0, 0, 23, SETVALUE_ROLLOVER_VALUE + SETVALUE_DISPLAY_VALUE + SETVALUE_NEXT_VALUE, LCD_SEG_L2_3_2, display_hours1);
		
		// Set value of wWorldtime.loc
		//////
	}
	
	// Clear button flags
	button.all_flags = 0;
}

// ******************************************
// @fn          display_worldtime
// @brief       Display routine.
// @param       u8 line			LINE2
//				u8 update		DISPLAY_LINE_UPDATE_FULL, DISPLAY_LINE_CLEAR
// @return      none
// note: 		does not handle English time, only 24H format.
// ******************************************
void display_worldtime(u8 line, u8 update)
{
	//u8 hour12; English time feature not yet supported
	
	if (update == DISPLAY_LINE_UPDATE_PARTIAL) 
	{
		if (sTime.drawFlag != 0) 
		{
			if (wWorldtime.display == DISPLAY_DEFAULT_VIEW)
			{
				switch (sTime.drawFlag)
				{
					case 3: // Display 24H Worldtime "HH" 
							display_chars(switch_seg(line, LCD_SEG_L1_3_2, LCD_SEG_L2_3_2), itoa(wWorldtime.hour, 2, 0), SEG_ON);
				
					case 2: display_chars(switch_seg(line, LCD_SEG_L1_1_0, LCD_SEG_L2_1_0), itoa(sTime.minute, 2, 0), SEG_ON);
				}
			} 
			else 
			{
				// display loc in ALT view
				display_chars(LCD_SEG_L2_5_0, wWorldtime.loc, SEG_ON);
			}
		} 
	}
	else if (update == DISPLAY_LINE_UPDATE_FULL) 
	{
		if (wWorldtime.display == DISPLAY_DEFAULT_VIEW) 
		{
			// Display 24H time "HH" 
			display_chars(switch_seg(line, LCD_SEG_L1_3_2, LCD_SEG_L2_3_2), itoa(wWorldtime.hour, 2, 0), SEG_ON);
			
			// Display minute
			display_chars(switch_seg(line, LCD_SEG_L1_1_0, LCD_SEG_L2_1_0), itoa(sTime.minute, 2, 0), SEG_ON); 
			display_symbol(switch_seg(line, LCD_SEG_L1_COL, LCD_SEG_L2_COL0), SEG_ON_BLINK_ON);
		}
		else 
		{
		 	//Display loc in ALT view
			display_chars(LCD_SEG_L2_5_0, wWorldtime.loc, SEG_ON);
			//display_symbol(switch_seg(line, LCD_SEG_L1_DP1, LCD_SEG_L2_DP), SEG_ON);
		}
	}
}

// ******************************************
// @fn          is_worldtime_active
// @brief       Returns 1 if worldtime module is currently active.
// @param       none
// @return      u8 
// note: originally used for scrolling but not sure if still needed
// ******************************************
u8 is_worldtime_active(void)
{
	return wWorldtime.mode == WORLDTIME_MODE_ON;
}

void do_worldtime_random(void)
{
	// function might need to change to accomodate
	// how we handle the loc table
	
	// Move the text
	u8 firstElem = wWorldtime.loc[0];
	u8 len = sizeof(wWorldtime.loc) / sizeof(u8);
	u8 i;
	for(i = 0; i < len - 1; i++) wWorldtime.loc[i] = wWorldtime.loc[i+1];
	wWorldtime.loc[len - 1] = firstElem;
	
	// Set display update flag
	display.flag.update_worldtime = 1;
}
