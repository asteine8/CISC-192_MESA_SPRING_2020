#include <curses.h>
#include <windows.h>

int main() {

    initscr();

    wclear(stdscr);

    for (int i = 0; i < 25; i++) {
        printw("hello world\n");
        wrefresh(stdscr);
        Sleep(100);
    }

    wrefresh(stdscr);

    endwin();

    return 0;
}