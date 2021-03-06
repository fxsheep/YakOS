/*
 * Copyright (c) 2013 Yannik Li(Yanqing Li)
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef _INIT_H_
#define _INIT_H_

#include <kernel/list.h>

#define CONSOLE_BUFFER_SIZE 256

#define CMD_FUNC(name)					\
	static int do_command_##name(char *args)
#define CMD_FUNC_NAME(name) do_command_##name

#define SHELL_COMMAND(name, command, description, cmd_func) \
	static struct shell_command name = { {NULL, NULL},  \
					     command,	    \
					     description,   \
					     cmd_func }

struct shell_command {
	struct list_head list;
	char *command;
	char *description;
	int (*func)(char *args);
};

void shell_unregister_command(struct shell_command *cmd);
void shell_register_command(struct shell_command *cmd);
int init_shell(void *arg);

#endif
