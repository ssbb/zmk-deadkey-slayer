if ((NOT CONFIG_ZMK_SPLIT) OR CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
  target_sources_ifdef(CONFIG_ZMK_DEADKEY_SLAYER app PRIVATE src/deadkey_slayer.c)
endif()
