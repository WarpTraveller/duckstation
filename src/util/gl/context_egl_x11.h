// SPDX-FileCopyrightText: 2019-2022 Connor McLaughlin <stenzek@gmail.com>
// SPDX-License-Identifier: (GPL-3.0 OR CC-BY-NC-ND-4.0)

#pragma once
#include "context_egl.h"

namespace GL {

class ContextEGLX11 final : public ContextEGL
{
public:
  ContextEGLX11(const WindowInfo& wi);
  ~ContextEGLX11() override;

  static std::unique_ptr<Context> Create(const WindowInfo& wi, const Version* versions_to_try,
                                         size_t num_versions_to_try);

  std::unique_ptr<Context> CreateSharedContext(const WindowInfo& wi) override;
  void ResizeSurface(u32 new_surface_width = 0, u32 new_surface_height = 0) override;

protected:
  EGLNativeWindowType GetNativeWindow(EGLConfig config) override;
};

} // namespace GL
