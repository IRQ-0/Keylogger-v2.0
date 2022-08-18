#include "keys.h"

std::string Keys::processKey(int chr) {
	static int type;
	std::string out;
	out.clear();
	switch (chr) {
		case CTRL_LEFT:
			out = "\n<ctrl left>";
		break;
		
		case CTRL_RIGHT:
			out = "\n<ctrl right>";
		break;
		
		case TAB:
			out = "\n<tab>";
		break;
		
		case BACKSPACE:
			out = "\n<backspace>";
		break;
		
		case ESC:
			out = "\n<esc>";
		break;
		
		case SHIFT_LEFT:
			out = "\n<shift left>";
		break;
		
		case SHIFT_RIGHT:
			out = "\n<shift right>";
		break;
		
		case WINDOWS:
			out = "\n<windows>";
		break;
		
		case CAPSLOCK:
			out = "\n<capslock>";
		break;
		
		case ENTER:
			out = "\n<enter>";
		break;
		
		case LEFT_ARROW:
			out = "\n<left arrow>";
		break;
		
		case RIGHT_ARROW:
			out = "\n<right arrow>";
		break;
		
		case UP_ARROW:
			out = "\n<up arrow>";
		break;
		
		case DOWN_ARROW:
			out = "\n<down arrow>";
		break;
		
		case INSERT:
			out = "\n<insert>";
		break;
		
		case DELETE:
			out = "\n<delete>";
		break;
		
		case HOME:
			out = "\n<home>";
		break;
		
		case END:
			out = "\n<end>";
		break;
		
		case PAGE_UP:
			out = "\n<page up>";
		break;
		
		case PAGE_DOWN:
			out = "\n<page down>";
		break;
		
		case PAUSE:
			out = "\n<pause>";
		break;
		
		case SCROLL_LOCK:
			out = "\n<scroll lock>";
		break;
		
		case PRINTSCREEN:
			out = "\n<printscreen>";
		break;
		
		case NUMLOCK:
			out = "\n<numlock>";
		break;
		
		case F1:
			out = "\n<f1>";
		break;
		
		case F2:
			out = "\n<f2>";
		break;
		
		case F3:
			out = "\n<f3>";
		break;
		
		case F4:
			out = "\n<f4>";
		break;
		
		case F5:
			out = "\n<f5>";
		break;
		
		case F6:
			out = "\n<f6>";
		break;
		
		case F7:
			out = "\n<f7>";
		break;
		
		case F8:
			out = "\n<f8>";
		break;
		
		case F9:
			out = "\n<f9>";
		break;
		
		case F10:
			out = "\n<f10>";
		break;
		
		case F11:
			out = "\n<f11>";
		break;
		
		case F12:
			out = "\n<f12>";
		break;
		
		default:
			if (type == SPECIAL) {
				std::string s(1, chr);
				out = "\n" + s;
			} else {
				out = chr;
			}
			
			type = NORMAL;
			return out;
	}
	type = SPECIAL;
	return out;
}
