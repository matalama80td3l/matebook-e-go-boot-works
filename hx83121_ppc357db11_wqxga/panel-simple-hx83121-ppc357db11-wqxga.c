// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2013, The Linux Foundation. All rights reserved.

static const struct drm_display_mode hx83121_ppc357db11_wqxga_mode = {
	.clock = (1600 + 118 + 20 + 40) * (2560 + 60 + 4 + 18) * 60 / 1000,
	.hdisplay = 1600,
	.hsync_start = 1600 + 118,
	.hsync_end = 1600 + 118 + 20,
	.htotal = 1600 + 118 + 20 + 40,
	.vdisplay = 2560,
	.vsync_start = 2560 + 60,
	.vsync_end = 2560 + 60 + 4,
	.vtotal = 2560 + 60 + 4 + 18,
	.width_mm = 166,
	.height_mm = 266,
};

static const struct panel_desc_dsi hx83121_ppc357db11_wqxga = {
	.desc = {
		.modes = &hx83121_ppc357db11_wqxga_mode,
		.num_modes = 1,
		.bpc = 8,
		.size = {
			.width = 166,
			.height = 266,
		},
		.connector_type = DRM_MODE_CONNECTOR_DSI,
	},
	.flags = MIPI_DSI_MODE_VIDEO | MIPI_DSI_CLOCK_NON_CONTINUOUS,
	.format = MIPI_DSI_FMT_RGB888,
	.lanes = 4,
};
