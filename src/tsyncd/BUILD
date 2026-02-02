# *******************************************************************************
# Copyright (c) 2025 Contributors to the Eclipse Foundation
#
# See the NOTICE file(s) distributed with this work for additional
# information regarding copyright ownership.
#
# This program and the accompanying materials are made available under the
# terms of the Apache License Version 2.0 which is available at
# https://www.apache.org/licenses/LICENSE-2.0
#
# SPDX-License-Identifier: Apache-2.0
# *******************************************************************************
package(
    default_visibility = ["//visibility:public"],
)

config_setting(
    name = "is_qnx",
    constraint_values = ["//platforms:qnx"],
)

config_setting(
    name = "is_linux",
    constraint_values = ["@platforms//os:linux"],
)

cc_binary(
    name = "tsyncd",
    srcs =
        [
            "config/config_loader.cpp",
            "daemon/main.cpp",
            "engine/time_sync_engine.cpp",
            "protocol/eth_protocol.cpp",
            "protocol/gptp_protocol.cpp",
            "protocol/net_identity.cpp",
            "protocol/ntp_client.cpp",
            "protocol/raw_socket.cpp",
        ] +
        # QNX-only
        select({
            ":is_qnx": ["platform/qnx/qnx_raw_shim.cpp"],
            "//conditions:default": [],
        }) +
        select({
            ":is_linux": ["platform/linux/linux_raw_shim.cpp"],
            "//conditions:default": [],
        }) + glob([
            "daemon/*.hpp",
            "engine/*.hpp",
            "protocol/*.hpp",
            "config/*.hpp",
            "platform/qnx/*.hpp",
            "platform/linux/*.hpp",
        ]),
    copts =
        ["-std=c++17"] +
        select({
            ":is_qnx": [
                "-D_QNX710_",
                "-D_QNX_SOURCE",
                "-D__EXTENSIONS__",
            ],
            "//conditions:default": [],
        }),
    data = [
        "config/tsyncd.conf",
    ],
    includes = [
        "config",
        "daemon",
        "engine",
        "platform/linux",
        "platform/qnx",
        "protocol",
    ],
    linkopts = select({
        ":is_qnx": [
            "-lsocket",
            "-lc",
            "-lc++",
        ],
        "//conditions:default": [
            "-lrt",
            "-lpthread",
            "-lstdc++",
            "-lsupc++",
        ],
    }),
    deps = [
        "//src/common:common_ipc",
        "//src/libscore_time:score_time",
    ],
)
