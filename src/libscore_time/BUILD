package(
    default_visibility = ["//visibility:public"],
)

config_setting(
    name = "is_qnx",
    constraint_values = ["//platforms:qnx"],
)

cc_library(
    name = "score_time",
    srcs = [
        "time_client/score_time.cpp",
    ],
    hdrs = glob(["include/**/*.hpp"]),
    deps = [
        "//src/common:common_ipc",
    ],
    strip_include_prefix = "include",
    include_prefix = "score_time",
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
