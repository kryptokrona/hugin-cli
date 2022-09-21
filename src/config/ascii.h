// Copyright (c) 2022-2022, The Kryptokrona Project
// 
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

const std::string windowsAsciiArt =
      "\n _                    _        _      \n"
        "| |__ _ _  _ _  ___ _| |_ ___ | |__ _ _  ___ ._ _  ___  \n"
        "| / /| '_>| | || . \\ | | / . \\| / /| '_>/ . \\| ' |<_> | \n"
        "|_\\_\\|_|  `_. ||  _/ |_| \\___/|_\\_\\|_|  \\___/|_|_|<___| \n"
        "          <___'|_|                                      \n";

const std::string nonWindowsAsciiArt =
      "\n                                                                            \n"
        "oooo                                            .             oooo     \n"
        "`888                                          .o8             `888                                                 \n"
        " 888  oooo  oooo d8b oooo    ooo oo.ooooo.  .o888oo  .ooooo.   888  oooo  oooo d8b  .ooooo.  ooo. .oo.    .oooo.   \n"
        " 888 .8P'   `888\"\"8P  `88.  .8'   888' `88b   888   d88' `88b  888 .8P'   `888\"\"8P d88' `88b `888P\"Y88b  `P  )88b  \n"
        " 888888.     888       `88..8'    888   888   888   888   888  888888.     888     888   888  888   888   .oP\"888  \n"
        " 888 `88b.   888        `888'     888   888   888 . 888   888  888 `88b.   888     888   888  888   888  d8(  888  \n"
        "o888o o888o d888b        .8'      888bod8P'   \"888\" `Y8bod8P' o888o o888o d888b    `Y8bod8P' o888o o888o `Y888\"\"8o \n"
        "                     .o..P'       888                                                                              \n"
        "                     `Y8P'       o888o                                                                             \n";

/* windows has some characters it won't display in a terminal. If your ascii
   art works fine on windows and linux terminals, just replace 'asciiArt' with
   the art itself, and remove these two #ifdefs and above ascii arts */
#ifdef _WIN32
const std::string asciiArt = windowsAsciiArt;
#else
const std::string asciiArt = nonWindowsAsciiArt;
#endif