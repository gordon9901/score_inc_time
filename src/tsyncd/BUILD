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
            "daemon/main.cpp",
            "engine/time_sync_engine.cpp",
            "protocol/ntp_client.cpp",
            "protocol/raw_socket.cpp",
            "protocol/eth_protocol.cpp",
            "protocol/gptp_protocol.cpp",
            "protocol/net_identity.cpp",
            "config/config_loader.cpp",
        ]
        # QNX-only
        + select({
            ":is_qnx": ["platform/qnx/qnx_raw_shim.cpp"],
            "//conditions:default": [],
        })
        + select({
            ":is_linux": ["platform/linux/linux_raw_shim.cpp"],
            "//conditions:default": [],
        })
        + glob(["daemon/*.hpp",
                "engine/*.hpp",
                "protocol/*.hpp",
                "config/*.hpp",
                "platform/qnx/*.hpp",
                "platform/linux/*.hpp",
        ]),
    includes = ["daemon",
                "engine",
                "protocol",
                "config",
                "platform/qnx",
                "platform/linux",
    ],
    copts =
        ["-std=c++17"]
        + select({
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
    deps = [
        "//src/common:common_ipc",
        "//src/libscore_time:score_time",
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
)
