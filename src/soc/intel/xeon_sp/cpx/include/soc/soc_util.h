/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef _SOC_UTIL_H_
#define _SOC_UTIL_H_

#include <hob_iiouds.h>
#include <hob_memmap.h>

struct iiostack_resource {
	uint8_t     no_of_stacks;
	STACK_RES   res[MAX_SOCKET * MAX_LOGIC_IIO_STACK];
};

void get_iiostack_info(struct iiostack_resource *info);

const struct SystemMemoryMapHob *get_system_memory_map(void);

uint32_t get_socket_stack_busno(uint32_t socket, uint32_t stack);

int soc_get_stack_for_port(int port);

#endif /* _SOC_UTIL_H_ */
