/********************************************************************************
* Copyright (c) 2025 Contributors to the Eclipse Foundation
*
* See the NOTICE file(s) distributed with this work for additional
* information regarding copyright ownership.
*
* This program and the accompanying materials are made available under the
* terms of the Apache License Version 2.0 which is available at
* https://www.apache.org/licenses/LICENSE-2.0
*
* SPDX-License-Identifier: Apache-2.0
********************************************************************************/
#pragma once

#include "tsync_types.hpp"

namespace tsyncd
{
    // Build IEEE 1588 ClockIdentity from interface address.
    int generate_clock_identity(ClockIdentity &ci, const char *iface_name);
}
