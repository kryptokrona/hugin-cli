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

#include <stdbool.h>

#include "window.h"

bool window_register_init()
{
	bool exit = false;
	WINDOW *win_login = window_create(0, 0, 0, 0);
	wbkgd(win_login, COLOR_PAIR(1));
	box(win_login, 0, 0);
	wrefresh(win_login);

	while (1)
	{
		/* read last pressed key */
		int ch = getch();

		/* if no key was waiting, ignore */
		if (ERR == ch)
			continue;

		/* if UP is pressed... */
		if (KEY_UP == ch)
		{
			/* ...do something with that key */
			/* and wait next key pressed */
			continue;
		}

		/* if CTRL + B is pressed, exit the loop */
		if (0x2 == ch)
		{
			exit = true;
			break;
		}

		/* else, display the key code */
		mvprintw(2,2,"code get: 0x%x\n", ch);

		/* and some refresh can be useful*/
		refresh();
	}

	return exit;
}