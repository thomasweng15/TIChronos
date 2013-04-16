// The prototype for writedate, 
// a feature that will print out the time
// in words.
// ******************************************
// Include section

// system
#include "project.h"

// driver
#include "display.h"
#include "vti_as.h"

// logic
#include "showmsg.h"
#include "simpliciti.h"
#include "user.h"
#include "string.h"

// ******************************************
// Global Variable section
struct showmsg sShowmsg;

// ******************************************
// Extern section

// ******************************************
// @fn          reset_showmsg
// @brief       Reset / INIT showmsg data.
// @param       none
// @return      none
// ******************************************
void reset_showmsg(void)
{
	// Reset state is not active
	sShowmsg.mode = SHOWMSG_MODE_OFF;

	strcpy((char *) sShowmsg.msg, " HELLO WORLD ");
	strcpy((char *) sShowmsg.altmsg, "SET"); 
	
	sShowmsg.display = DISPLAY_DEFAULT_VIEW;
}

// ******************************************
// @fn          sx_showmsg
// @brief       
// @param       
// @return      none
// ******************************************
void sx_showmsg(u8 line)
{
	// Toggle display items
	if (sShowmsg.display == DISPLAY_DEFAULT_VIEW) {
		sShowmsg.display = DISPLAY_ALTERNATIVE_VIEW;
	} 
	else {								
		sShowmsg.display = DISPLAY_DEFAULT_VIEW;
	}
}

// ******************************************
// @fn          display_showmsg
// @brief       Display routine.
// @param       u8 line			LINE1
//		u8 update		DISPLAY_LINE_UPDATE_FULL, DISPLAY_LINE_CLEAR
// @return      none
// ******************************************
void display_showmsg(u8 line, u8 update)
{
	if (sShowmsg.display == DISPLAY_DEFAULT_VIEW)
	{
		if (update == DISPLAY_LINE_UPDATE_FULL)
		{
			display_chars(LCD_SEG_L1_3_0, sShowmsg.msg, SEG_ON);

			// Set mode
			sShowmsg.mode = SHOWMSG_MODE_ON;
		}
		else if (update == DISPLAY_LINE_UPDATE_PARTIAL)
		{
			display_chars(LCD_SEG_L1_3_0, sShowmsg.msg, SEG_ON);
		}
		else if (update == DISPLAY_LINE_CLEAR)
		{
			reset_showmsg();
		}
	}
	else 
	{
		display_chars(LCD_SEG_L1_3_0, sShowmsg.altmsg, SEG_ON);
	}
}

// ******************************************
// @fn          is_showmsg_active
// @brief       Returns 1 if showmsg module is currently active and needs doing random stuff.
// @param       none
// @return      u8		1 = showmsg module needs random stuff
// ******************************************
u8 is_showmsg_active(void)
{
	return sShowmsg.mode == SHOWMSG_MODE_ON;
}

void do_showmsg_random(void)
{
	// Move the text
	u8 firstElem = sShowmsg.msg[0];
	u8 len = sizeof(sShowmsg.msg) / sizeof(u8);
	u8 i;
	for(i = 0; i < len - 1; i++) sShowmsg.msg[i] = sShowmsg.msg[i+1];
	sShowmsg.msg[len - 1] = firstElem;
	

	// Set display update flag
	display.flag.update_showmsg = 1;
}
