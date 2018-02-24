#pragma once

#include "libretro/Components.h"

#include <SDL_events.h>

class KeyBinds
{
public:
  enum class Action
  {
    kNothing,
    // Joypad buttons
    kButtonUp,
    kButtonDown,
    kButtonLeft,
    kButtonRight,
    kButtonX,
    kButtonY,
    kButtonA,
    kButtonB,
    kButtonL,
    kButtonR,
    kButtonL2,
    kButtonR2,
    kButtonL3,
    kButtonR3,
    kButtonSelect,
    kButtonStart,
    // State state management
    kSaveState,
    kLoadState,
    // Emulation speed
    kPauseToggle,
    kFastForward,
    kStep,
    // Screenshot
    kScreenshot
  };

  bool init(libretro::LoggerComponent* logger);
  void destroy() {}

  Action translate(const SDL_KeyboardEvent* event, unsigned* extra);

  // TODO: showDialog() to configure the key bindings

protected:
  libretro::LoggerComponent* _logger;

  unsigned _slot;
  bool _ff;
};
