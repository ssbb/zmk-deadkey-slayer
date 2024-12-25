/*
 * Copyright (c) 2024 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zephyr/device.h>
#include <zephyr/logging/log.h>
#include <zmk/keymap.h>
#include <zmk/event_manager.h>
#include <zmk/events/keycode_state_changed.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

static int deadkey_slayer_keycode_state_changed_listener(const zmk_event_t *eh) {
    struct zmk_keycode_state_changed *ev = as_zmk_keycode_state_changed(eh);

    if (ev->keycode > 0xff) {
        LOG_DBG("event dropped usage_page 0x%02X keycode 0x%02X", ev->usage_page, ev->keycode);
        return (ZMK_EV_EVENT_HANDLED);
    } else {
        return (ZMK_EV_EVENT_BUBBLE);
    }
}

ZMK_LISTENER(deadkey_slayer, deadkey_slayer_keycode_state_changed_listener);
ZMK_SUBSCRIPTION(deadkey_slayer, zmk_keycode_state_changed);
