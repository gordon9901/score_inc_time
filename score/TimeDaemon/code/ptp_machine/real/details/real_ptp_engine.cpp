/********************************************************************************
 * Copyright (c) 2026 Contributors to the Eclipse Foundation
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
#include "score/TimeDaemon/code/ptp_machine/real/details/real_ptp_engine.h"

#include "score/TimeDaemon/code/common/logging_contexts.h"
#include "score/mw/log/logging.h"

namespace score
{
namespace td
{
namespace details
{

RealPTPEngine::RealPTPEngine(std::string ipc_name) noexcept : ipc_name_{std::move(ipc_name)} {}

bool RealPTPEngine::Initialize()
{
    if (initialized_)
        return true;

    initialized_ = receiver_.Init(ipc_name_);
    if (initialized_)
    {
        score::mw::log::LogInfo(kGPtpMachineContext) << "RealPTPEngine: connected to IPC channel " << ipc_name_;
    }
    else
    {
        score::mw::log::LogError(kGPtpMachineContext) << "RealPTPEngine: failed to open IPC channel " << ipc_name_;
    }
    return initialized_;
}

bool RealPTPEngine::Deinitialize()
{
    if (initialized_)
    {
        receiver_.Close();
        initialized_ = false;
    }
    return true;
}

bool RealPTPEngine::ReadPTPSnapshot(PtpTimeInfo& info)
{
    if (!initialized_)
        return false;

    auto result = receiver_.Receive();
    if (!result.has_value())
        return false;

    info = result.value();
    return true;
}

}  // namespace details
}  // namespace td
}  // namespace score
