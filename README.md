# zmk-deadkey-slayer

This very simple module is used to drop illegal keycodes (anything above `0xFF`), which are usually used as indicators for certain behaviors (e.g., adaptive key, auto layer, output listener, etc.).

Please note that user module listeners are always processed before ZMK core ones, so this module can't be used, for example, to reset sticky keys (because the key will be dropped before it reaches ZMK sticky keys listener).

## Usage

Add the following entries to `remotes` and `projects` in `config/west.yml`.

```yaml
manifest:
  remotes:
    - name: zmkfirmware
      url-base: https://github.com/zmkfirmware
    - name: ssbb
      url-base: https://github.com/ssbb
  projects:
    - name: zmk
      remote: zmkfirmware
      import: app/west.yml
    - name: zmk-deadkey-slayer
      remote: ssbb
      revision: v1
  self:
    path: config
```

> [!IMPORTANT]
> **This module should be the last one in either `projects` or in `ZMK_EXTRA_MODULES` if building locally, due to how ZMK defines the order of listeners.**
