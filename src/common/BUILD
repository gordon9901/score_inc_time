package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "common_ipc",
    srcs = [
        "shared_memory/shm_region.cpp",
    ],
    hdrs = glob(["include/**/*.hpp"]),
    strip_include_prefix = "include",
)
