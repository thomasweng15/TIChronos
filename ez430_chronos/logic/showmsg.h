#ifndef SHOWMSG_H_
#define SHOWMSG_H_

// ******************************************
// Defines section
#define SHOWMSG_MODE_OFF		(0u)
#define SHOWMSG_MODE_ON			(1u)

// ******************************************
// Global Variable section
struct showmsg
{
	u8  display;
	// SHOWMSG_MODE_OFF, SHOWMSG_MODE_ON
	u8			mode;
	// Data to display
	u8			msg[13];
	u8			altmsg[3];
};
extern struct showmsg sShowmsg;

// ******************************************
// Extern section
extern void reset_showmsg(void);
extern void sx_showmsg(u8 line);
extern void display_showmsg(u8 line, u8 update);
extern u8 is_showmsg_active(void);
extern void do_showmsg_random(void);

#endif /*SHOWMSG_H_*/
