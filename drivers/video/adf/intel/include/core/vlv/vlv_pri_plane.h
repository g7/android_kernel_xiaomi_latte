/*
 * Copyright (C) 2014, Intel Corporation.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef VLV_PRI_PLANE_H
#define VLV_PRI_PLANE_H

#include "core/intel_dc_config.h"
#include "vlv_dc_hw.h"

enum {
	PLANE_PIXEL_FORMAT_C8 = 0,
};

struct pri_plane_regs_value {
	u32 dspcntr;
	u32 stride;
	unsigned long linearoff;
	unsigned long tileoff;
	unsigned long surfaddr;
};

struct vlv_pri_plane_context {
	struct pri_plane_regs_value regs;
	u32 plane;
};

struct vlv_pri_plane {
	struct intel_plane base;
	struct vlv_pri_plane_context ctx;
};

static inline struct vlv_pri_plane *to_vlv_pri_plane(struct intel_plane *plane)
{
	return container_of(plane, struct vlv_pri_plane, base);
}

int vlv_pri_plane_init(struct vlv_pri_plane *pplane,
		struct device *dev, u8 idx);
void vlv_pri_plane_destroy(struct vlv_pri_plane *plane);
extern unsigned long vlv_compute_page_offset(int *x, int *y,
					unsigned int tiling_mode,
					unsigned int cpp,
					unsigned int pitch);
#endif