#ifndef WORLDTIME_H_
#define WORLDTIME_H_

// ******************************************
// Defines section
#define WORLDTIME_MODE_OFF		(0u)
#define WORLDTIME_MODE_ON		(1u)

// ******************************************
// Global Variable section
struct worldtime
{
	u8  display;
	
	u8	mode; 		// WORLDTIME_MODE_OFF, WORLDTIME_MODE_ON
	
	u8 	hour; 		// Worldtime hour -- only hours are different
	
	u8	loc[10]; 	// world location to display
	
	// fixed size array containing pointers to world location strings
	u8 *wtable[24]; 
};
extern struct worldtime wWorldtime;

		

// ******************************************
// Extern section
extern void reset_worldtime(void);
extern void sx_worldtime(u8 line);
extern void mx_worldtime(u8 line);
extern void display_worldtime(u8 line, u8 update);
extern u8 is_worldtime_active(void);
extern void do_worldtime_random(void);

#endif /*WORLDTIME_H_*/
