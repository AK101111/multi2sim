/*
 *  Multi2Sim
 *  Copyright (C) 2012  Rafael Ubal (ubal@ece.neu.edu)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef RUNTIME_OPENCL_FIBERS_H
#define RUNTIME_OPENCL_FIBERS_H

typedef void (*fiber_proc_t)(void);
typedef void (*return_address_t)(void);

struct fiber_t
{
	void *esp;
	void *eip;
	void *stack_bottom;
	unsigned int stack_size;
};

void make_fiber(struct fiber_t *fiber, fiber_proc_t fiber_proc, int num_args, ...);
void make_fiber_ex(struct fiber_t *fiber, fiber_proc_t fiber_proc, return_address_t return_proc, int arg_size, void *args);
void switch_fiber(struct fiber_t *current, struct fiber_t *dest, void *reg_values);

#endif