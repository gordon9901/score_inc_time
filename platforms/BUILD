package(
    default_visibility = ["//visibility:public"],
)

constraint_setting(
    name = "os",
)

constraint_value(
    name = "qnx",
    constraint_setting = ":os",
)

platform(
    name = "linux_aarch64",
    constraint_values = [
        "@platforms//cpu:aarch64",
        "@platforms//os:linux",
    ],
)

platform(
    name = "qnx_aarch64",
    constraint_values = [
        "@platforms//cpu:aarch64",
        ":qnx",
    ],
)
