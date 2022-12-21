// Copyright (c) 2022-2022, The Kryptokrona Developers
//
// Created by Marcus Cvjeticanin
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
// this list of
//    conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list
//    of conditions and the following disclaimer in the documentation and/or
//    other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors
// may be
//    used to endorse or promote products derived from this software without
//    specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#include "ncurses.h"

#include "window.h"

WINDOW *window_main_init()
{
	WINDOW *menu_win = window_create(10, 95, 18, 2);
	wbkgd(menu_win, COLOR_PAIR(1));
	box(menu_win, 0, 0);

	wrefresh(menu_win);
	keypad(menu_win, true);

	return menu_win;
}

int window_main_selected_choice(WINDOW *win_main)
{
	const char *MENU_CHOICES[3] = {
		"Login",
		"Register",
		"Quit"
	};
	const char *MENU_CHOICES_DESC[3] = {
		"Login with your account.",
		"Register a new account.",
		"Quit the application."
	};
	int choice;
	int highlight = 0;

	while (1)
	{
		for (int i = 0; i < 3; i++)
		{
			if (i == highlight)
				wattron(win_main, A_REVERSE);

			mvwprintw(win_main, i + 1, 1, "%-25s%-20s", MENU_CHOICES[i], MENU_CHOICES_DESC[i]);
			wattroff(win_main, A_REVERSE);
		}
		choice = wgetch(win_main);

		switch (choice)
		{
		case KEY_UP:
			highlight--;
			if (highlight == -1)
				highlight = 0;
			break;

		case KEY_DOWN:
			highlight++;
			if (highlight > 2)
				highlight = 2;
			break;

		default:
			break;
		}

		// 10 is the enter key
		if (choice == 10)
			break;
	}

	return highlight;
}
