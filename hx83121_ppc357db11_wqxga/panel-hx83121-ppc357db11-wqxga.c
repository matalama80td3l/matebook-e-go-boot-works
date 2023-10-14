// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2023 FIXME
// Generated with linux-mdss-dsi-panel-driver-generator from vendor device tree:
//   Copyright (c) 2013, The Linux Foundation. All rights reserved. (FIXME)

#include <linux/backlight.h>
#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/module.h>
#include <linux/of.h>

#include <video/mipi_display.h>

#include <drm/drm_mipi_dsi.h>
#include <drm/drm_modes.h>
#include <drm/drm_panel.h>

struct hx83121_ppc357db11_wqxga {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct gpio_desc *reset_gpio;
	bool prepared;
};

static inline
struct hx83121_ppc357db11_wqxga *to_hx83121_ppc357db11_wqxga(struct drm_panel *panel)
{
	return container_of(panel, struct hx83121_ppc357db11_wqxga, panel);
}

static void hx83121_ppc357db11_wqxga_reset(struct hx83121_ppc357db11_wqxga *ctx)
{
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(2000, 3000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	usleep_range(2000, 3000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	msleep(55);
}

static int hx83121_ppc357db11_wqxga_on(struct hx83121_ppc357db11_wqxga *ctx)
{
	struct mipi_dsi_device *dsi = ctx->dsi;
	struct device *dev = &dsi->dev;
	int ret;

	mipi_dsi_dcs_write_seq(dsi, 0xb9, 0x83, 0x12, 0x1a, 0x55, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0xb1,
			       0x1c, 0x6b, 0x6b, 0x27, 0xe7, 0x00, 0x1b, 0x11,
			       0x26, 0x26, 0x2d, 0x2d, 0x1a, 0x33, 0x31, 0x40,
			       0xcd, 0xff, 0x1a, 0x05, 0x15, 0x98, 0x00, 0x88,
			       0xff, 0xff, 0xff, 0xcf);
	mipi_dsi_dcs_write_seq(dsi, 0xb2,
			       0x00, 0x6a, 0x40, 0x00, 0x00, 0x14, 0x3a, 0x40,
			       0x7a, 0x02, 0x80, 0x21, 0x21, 0x00, 0x00, 0x10,
			       0x27);
	mipi_dsi_dcs_write_seq(dsi, 0xb4,
			       0x08, 0x7f, 0x08, 0x7f, 0x08, 0x7f, 0x0a, 0x7f,
			       0x0a, 0x7f, 0x0a, 0x7f, 0x0a, 0x7f, 0x00, 0x00,
			       0x0e, 0x0f, 0x00, 0x2d, 0x0b, 0x06, 0x0b, 0x00,
			       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			       0x00, 0x00, 0xff, 0x00, 0xff, 0x14, 0x66);
	mipi_dsi_dcs_write_seq(dsi, 0xbc, 0x06, 0x02);
	mipi_dsi_dcs_write_seq(dsi, 0xc0, 0x34, 0x34, 0x44, 0x00, 0x08, 0xd8);
	mipi_dsi_dcs_write_seq(dsi, 0xcc, 0x02);
	mipi_dsi_dcs_write_seq(dsi, 0xd1, 0x07);
	mipi_dsi_dcs_write_seq(dsi, 0xd3,
			       0x00, 0xc0, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04,
			       0x14, 0x02, 0x07, 0x07, 0x07, 0x31, 0x13, 0x12,
			       0x12, 0x12, 0x03, 0x03, 0x03, 0x32, 0x10, 0x11,
			       0x00, 0x11, 0x32, 0x10, 0x03, 0x00, 0x03, 0x32,
			       0x10, 0x03, 0x00, 0x03, 0x00, 0x00, 0xff, 0x00);

	ret = mipi_dsi_dcs_set_display_brightness(dsi, 0x0008);
	if (ret < 0) {
		dev_err(dev, "Failed to set display brightness: %d\n", ret);
		return ret;
	}

	mipi_dsi_dcs_write_seq(dsi, 0xc9, 0x00, 0x05, 0x80, 0xa5, 0x01);
	mipi_dsi_dcs_write_seq(dsi, 0xcb, 0x00, 0x13, 0x38, 0x00, 0x0b, 0x2d);
	mipi_dsi_dcs_write_seq(dsi, 0xd9, 0x0c, 0x04, 0x02);
	mipi_dsi_dcs_write_seq(dsi, 0xd5,
			       0x19, 0x19, 0x18, 0x18, 0x02, 0x02, 0x03, 0x03,
			       0x04, 0x04, 0x05, 0x05, 0x06, 0x06, 0x07, 0x07,
			       0x00, 0x00, 0x01, 0x01, 0x18, 0x18, 0x40, 0x40,
			       0x20, 0x20, 0x18, 0x18, 0x18, 0x18, 0x40, 0x40,
			       0x18, 0x18, 0x2f, 0x2f, 0x31, 0x31, 0x2f, 0x2f,
			       0x31, 0x31, 0x18, 0x18, 0x41, 0x41, 0x41, 0x41);
	mipi_dsi_dcs_write_seq(dsi, 0xd6,
			       0x40, 0x40, 0x18, 0x18, 0x05, 0x05, 0x04, 0x04,
			       0x03, 0x03, 0x02, 0x02, 0x01, 0x01, 0x00, 0x00,
			       0x07, 0x07, 0x06, 0x06, 0x18, 0x18, 0x19, 0x19,
			       0x20, 0x20, 0x18, 0x18, 0x18, 0x18, 0x40, 0x40,
			       0x18, 0x18, 0x2f, 0x2f, 0x31, 0x31, 0x2f, 0x2f,
			       0x31, 0x31, 0x18, 0x18, 0x41, 0x41, 0x41, 0x41);
	mipi_dsi_dcs_write_seq(dsi, 0xe1,
			       0x11, 0x00, 0x00, 0x89, 0x30, 0x80, 0x0a, 0x00,
			       0x06, 0x40, 0x00, 0x28, 0x06, 0x40, 0x06, 0x40,
			       0x02, 0x00, 0x04, 0x21, 0x00, 0x20, 0x05, 0xd0,
			       0x00, 0x16, 0x00, 0x0c, 0x02, 0x77, 0x00, 0xda,
			       0x18, 0x00, 0x10, 0xe0, 0x03, 0x0c, 0x20, 0x00,
			       0x06, 0x0b, 0x0b, 0x33, 0x0e, 0x1c, 0x2a, 0x38,
			       0x46, 0x54, 0x62, 0x69, 0x70, 0x77, 0x79, 0x7b,
			       0x7d, 0x7e, 0x01, 0x02, 0x01, 0x00, 0x09);
	mipi_dsi_dcs_write_seq(dsi, 0xbd, 0x01);
	mipi_dsi_dcs_write_seq(dsi, 0xb1, 0x01, 0x23, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0xcb,
			       0x13, 0x55, 0x03, 0x28, 0x0d, 0x08, 0x0b);
	mipi_dsi_dcs_write_seq(dsi, 0xd6, 0x02, 0x04, 0x21, 0x02, 0x04, 0x21);
	mipi_dsi_dcs_write_seq(dsi, 0xd8,
			       0x20, 0x00, 0x02, 0x22, 0x00, 0x00, 0x20, 0x00,
			       0x02, 0x22, 0x00, 0x00, 0x20, 0x00, 0x02, 0x22,
			       0x00, 0x00, 0x20, 0x00, 0x02, 0x22, 0x00, 0x00,
			       0x20, 0x00, 0x02, 0x22, 0x00, 0x00, 0x20, 0x00,
			       0x02, 0x22, 0x00, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0xe1,
			       0x40, 0x09, 0xbe, 0x19, 0xfc, 0x19, 0xfa, 0x19,
			       0xf8, 0x1a, 0x38, 0x1a, 0x78, 0x1a, 0xb6, 0x2a,
			       0xf6, 0x2b, 0x34, 0x2b, 0x74, 0x3b, 0x74, 0x63,
			       0xf4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0xbd, 0x02);
	mipi_dsi_dcs_write_seq(dsi, 0xd8,
			       0xaf, 0xff, 0xfa, 0xfa, 0xbf, 0xea, 0xaf, 0xff,
			       0xfa, 0xfa, 0xbf, 0xea);
	mipi_dsi_dcs_write_seq(dsi, 0xbf, 0x72);
	mipi_dsi_dcs_write_seq(dsi, 0xbd, 0x03);
	mipi_dsi_dcs_write_seq(dsi, 0xd8,
			       0xaa, 0xaa, 0xaa, 0xab, 0xbf, 0xea, 0xaa, 0xaa,
			       0xaa, 0xab, 0xbf, 0xea, 0xaf, 0xff, 0xfa, 0xfa,
			       0xbf, 0xea, 0xaf, 0xff, 0xfa, 0xfa, 0xbf, 0xea);
	mipi_dsi_dcs_write_seq(dsi, 0xe1, 0x01, 0x3f);
	mipi_dsi_dcs_write_seq(dsi, 0xbd, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0xd8,
			       0xea, 0xaa, 0xaa, 0xae, 0xaa, 0xaf, 0xea, 0xaa,
			       0xaa, 0xae, 0xaa, 0xaf, 0xe0, 0x00, 0x0a, 0x2e,
			       0x80, 0x2f, 0xe0, 0x00, 0x0a, 0x2e, 0x80, 0x2f,
			       0xe0, 0x00, 0x0a, 0x2e, 0x80, 0x2f, 0xe0, 0x00,
			       0x0a, 0x2e, 0x80, 0x2f);
	mipi_dsi_dcs_write_seq(dsi, 0xe7,
			       0x05, 0x0a, 0x0a, 0x25, 0x22, 0x44, 0x02, 0x23,
			       0x44, 0x19, 0x02);
	mipi_dsi_dcs_write_seq(dsi, 0xbd, 0x01);
	mipi_dsi_dcs_write_seq(dsi, 0xe7,
			       0x02, 0x00, 0xfa, 0x01, 0x02, 0x09, 0xfe, 0x0a,
			       0x48, 0x04, 0x04, 0x26);
	mipi_dsi_dcs_write_seq(dsi, 0xbd, 0x02);
	mipi_dsi_dcs_write_seq(dsi, 0xe7,
			       0x01, 0x03, 0x01, 0x03, 0x01, 0x03, 0x02, 0x02,
			       0x02, 0x02, 0x00, 0x02, 0x81, 0x02, 0x40, 0x00,
			       0x3a, 0x90, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
			       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			       0x00, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0xbd, 0x00);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_WRITE_POWER_SAVE, 0x01);
	mipi_dsi_dcs_write_seq(dsi, 0xe9, 0xc7);
	mipi_dsi_dcs_write_seq(dsi, 0xbf, 0x01);
	mipi_dsi_dcs_write_seq(dsi, 0xe9, 0x3f);
	mipi_dsi_dcs_write_seq(dsi, 0xe9, 0xde);
	mipi_dsi_dcs_write_seq(dsi, 0xb1, 0xcc, 0x03, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0xe9, 0x3f);
	mipi_dsi_dcs_write_seq(dsi, 0xd0, 0x07, 0xc0, 0x08, 0x03, 0x11, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0xe4,
			       0x2d, 0x03, 0x41, 0x2c, 0x1e, 0x1e, 0x1e, 0x1e,
			       0x00, 0x00, 0x00, 0x01, 0x14);
	mipi_dsi_dcs_write_seq(dsi, 0xbd, 0x01);
	mipi_dsi_dcs_write_seq(dsi, 0xe4,
			       0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0xe1,
			       0xc7, 0xb2, 0xa0, 0x90, 0x81, 0x75, 0x69, 0x5f,
			       0x55, 0x4c, 0x44, 0x3d, 0x36, 0x2f, 0x2a, 0x24,
			       0x1e, 0x1a, 0x15, 0x12, 0x0d, 0x0b, 0x0a, 0x54,
			       0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55);
	mipi_dsi_dcs_write_seq(dsi, 0xbd, 0x03);
	mipi_dsi_dcs_write_seq(dsi, 0xe4,
			       0xcc, 0xf3, 0x19, 0x40, 0x66, 0x8c, 0xb2, 0xd9,
			       0xff, 0xfa, 0xff, 0x03);
	mipi_dsi_dcs_write_seq(dsi, 0xbd, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0xe9, 0xcf);
	mipi_dsi_dcs_write_seq(dsi, 0xba, 0x03);
	mipi_dsi_dcs_write_seq(dsi, 0xe9, 0x3f);
	mipi_dsi_dcs_write_seq(dsi, 0xb9, 0x00, 0x00, 0x00);

	ret = mipi_dsi_dcs_exit_sleep_mode(dsi);
	if (ret < 0) {
		dev_err(dev, "Failed to exit sleep mode: %d\n", ret);
		return ret;
	}
	msleep(128);

	ret = mipi_dsi_dcs_set_display_on(dsi);
	if (ret < 0) {
		dev_err(dev, "Failed to set display on: %d\n", ret);
		return ret;
	}
	msleep(21);

	return 0;
}

static int hx83121_ppc357db11_wqxga_off(struct hx83121_ppc357db11_wqxga *ctx)
{
	struct mipi_dsi_device *dsi = ctx->dsi;
	struct device *dev = &dsi->dev;
	int ret;

	ret = mipi_dsi_dcs_enter_sleep_mode(dsi);
	if (ret < 0) {
		dev_err(dev, "Failed to enter sleep mode: %d\n", ret);
		return ret;
	}
	msleep(32);

	return 0;
}

static int hx83121_ppc357db11_wqxga_prepare(struct drm_panel *panel)
{
	struct hx83121_ppc357db11_wqxga *ctx = to_hx83121_ppc357db11_wqxga(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	if (ctx->prepared)
		return 0;

	hx83121_ppc357db11_wqxga_reset(ctx);

	ret = hx83121_ppc357db11_wqxga_on(ctx);
	if (ret < 0) {
		dev_err(dev, "Failed to initialize panel: %d\n", ret);
		gpiod_set_value_cansleep(ctx->reset_gpio, 1);
		return ret;
	}

	ctx->prepared = true;
	return 0;
}

static int hx83121_ppc357db11_wqxga_unprepare(struct drm_panel *panel)
{
	struct hx83121_ppc357db11_wqxga *ctx = to_hx83121_ppc357db11_wqxga(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	if (!ctx->prepared)
		return 0;

	ret = hx83121_ppc357db11_wqxga_off(ctx);
	if (ret < 0)
		dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

	gpiod_set_value_cansleep(ctx->reset_gpio, 1);

	ctx->prepared = false;
	return 0;
}

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

static int hx83121_ppc357db11_wqxga_get_modes(struct drm_panel *panel,
					      struct drm_connector *connector)
{
	struct drm_display_mode *mode;

	mode = drm_mode_duplicate(connector->dev, &hx83121_ppc357db11_wqxga_mode);
	if (!mode)
		return -ENOMEM;

	drm_mode_set_name(mode);

	mode->type = DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED;
	connector->display_info.width_mm = mode->width_mm;
	connector->display_info.height_mm = mode->height_mm;
	drm_mode_probed_add(connector, mode);

	return 1;
}

static const struct drm_panel_funcs hx83121_ppc357db11_wqxga_panel_funcs = {
	.prepare = hx83121_ppc357db11_wqxga_prepare,
	.unprepare = hx83121_ppc357db11_wqxga_unprepare,
	.get_modes = hx83121_ppc357db11_wqxga_get_modes,
};

static int hx83121_ppc357db11_wqxga_bl_update_status(struct backlight_device *bl)
{
	struct mipi_dsi_device *dsi = bl_get_data(bl);
	u16 brightness = backlight_get_brightness(bl);
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_set_display_brightness_large(dsi, brightness);
	if (ret < 0)
		return ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	return 0;
}

// TODO: Check if /sys/class/backlight/.../actual_brightness actually returns
// correct values. If not, remove this function.
static int hx83121_ppc357db11_wqxga_bl_get_brightness(struct backlight_device *bl)
{
	struct mipi_dsi_device *dsi = bl_get_data(bl);
	u16 brightness;
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_get_display_brightness_large(dsi, &brightness);
	if (ret < 0)
		return ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	return brightness;
}

static const struct backlight_ops hx83121_ppc357db11_wqxga_bl_ops = {
	.update_status = hx83121_ppc357db11_wqxga_bl_update_status,
	.get_brightness = hx83121_ppc357db11_wqxga_bl_get_brightness,
};

static struct backlight_device *
hx83121_ppc357db11_wqxga_create_backlight(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	const struct backlight_properties props = {
		.type = BACKLIGHT_RAW,
		.brightness = 425,
		.max_brightness = 425,
	};

	return devm_backlight_device_register(dev, dev_name(dev), dev, dsi,
					      &hx83121_ppc357db11_wqxga_bl_ops, &props);
}

static int hx83121_ppc357db11_wqxga_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct hx83121_ppc357db11_wqxga *ctx;
	int ret;

	ctx = devm_kzalloc(dev, sizeof(*ctx), GFP_KERNEL);
	if (!ctx)
		return -ENOMEM;

	ctx->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
	if (IS_ERR(ctx->reset_gpio))
		return dev_err_probe(dev, PTR_ERR(ctx->reset_gpio),
				     "Failed to get reset-gpios\n");

	ctx->dsi = dsi;
	mipi_dsi_set_drvdata(dsi, ctx);

	dsi->lanes = 4;
	dsi->format = MIPI_DSI_FMT_RGB888;
	dsi->mode_flags = MIPI_DSI_MODE_VIDEO | MIPI_DSI_CLOCK_NON_CONTINUOUS;

	drm_panel_init(&ctx->panel, dev, &hx83121_ppc357db11_wqxga_panel_funcs,
		       DRM_MODE_CONNECTOR_DSI);
	ctx->panel.prepare_prev_first = true;

	ctx->panel.backlight = hx83121_ppc357db11_wqxga_create_backlight(dsi);
	if (IS_ERR(ctx->panel.backlight))
		return dev_err_probe(dev, PTR_ERR(ctx->panel.backlight),
				     "Failed to create backlight\n");

	drm_panel_add(&ctx->panel);

	ret = mipi_dsi_attach(dsi);
	if (ret < 0) {
		dev_err(dev, "Failed to attach to DSI host: %d\n", ret);
		drm_panel_remove(&ctx->panel);
		return ret;
	}

	return 0;
}

static void hx83121_ppc357db11_wqxga_remove(struct mipi_dsi_device *dsi)
{
	struct hx83121_ppc357db11_wqxga *ctx = mipi_dsi_get_drvdata(dsi);
	int ret;

	ret = mipi_dsi_detach(dsi);
	if (ret < 0)
		dev_err(&dsi->dev, "Failed to detach from DSI host: %d\n", ret);

	drm_panel_remove(&ctx->panel);
}

static const struct of_device_id hx83121_ppc357db11_wqxga_of_match[] = {
	{ .compatible = "mdss,hx83121-ppc357db11-wqxga" }, // FIXME
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, hx83121_ppc357db11_wqxga_of_match);

static struct mipi_dsi_driver hx83121_ppc357db11_wqxga_driver = {
	.probe = hx83121_ppc357db11_wqxga_probe,
	.remove = hx83121_ppc357db11_wqxga_remove,
	.driver = {
		.name = "panel-hx83121-ppc357db11-wqxga",
		.of_match_table = hx83121_ppc357db11_wqxga_of_match,
	},
};
module_mipi_dsi_driver(hx83121_ppc357db11_wqxga_driver);

MODULE_AUTHOR("linux-mdss-dsi-panel-driver-generator <fix@me>"); // FIXME
MODULE_DESCRIPTION("DRM driver for ss_dsi_panel_HX83121_PPC357DB11_WQXGA");
MODULE_LICENSE("GPL");
