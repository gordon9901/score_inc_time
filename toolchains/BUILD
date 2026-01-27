load(":cc_toolchain_config.bzl", "aarch64_toolchain_config")

package(
    default_visibility = ["//visibility:public"],
)

# ========== Linux aarch64 ==========

filegroup(
    name = "linux_aarch64_files",
    srcs = [],
)

aarch64_toolchain_config(
    name = "linux_aarch64_toolchain_config",
    toolchain_identifier = "linux_aarch64_gnu",
    target_system_name = "aarch64-linux-gnu",
    compiler = "gcc",
    tool_path_names = [
        "ar",
        "cpp",
        "gcc",
        "g++",
        "ld",
        "nm",
        "objcopy",
        "objdump",
        "strip",
    ],
    tool_path_paths = [
        "/opt/bstos/linux-23/sysroots/x86_64-bstsdk-linux/usr/bin/aarch64-bst-linux/aarch64-bst-linux-ar",
        "/opt/bstos/linux-23/sysroots/x86_64-bstsdk-linux/usr/bin/aarch64-bst-linux/aarch64-bst-linux-cpp",
        "/opt/bstos/linux-23/sysroots/x86_64-bstsdk-linux/usr/bin/aarch64-bst-linux/aarch64-bst-linux-gcc",
        "/opt/bstos/linux-23/sysroots/x86_64-bstsdk-linux/usr/bin/aarch64-bst-linux/aarch64-bst-linux-g++",
        "/opt/bstos/linux-23/sysroots/x86_64-bstsdk-linux/usr/bin/aarch64-bst-linux/aarch64-bst-linux-ld",
        "/opt/bstos/linux-23/sysroots/x86_64-bstsdk-linux/usr/bin/aarch64-bst-linux/aarch64-bst-linux-nm",
        "/opt/bstos/linux-23/sysroots/x86_64-bstsdk-linux/usr/bin/aarch64-bst-linux/aarch64-bst-linux-objcopy",
        "/opt/bstos/linux-23/sysroots/x86_64-bstsdk-linux/usr/bin/aarch64-bst-linux/aarch64-bst-linux-objdump",
        "/opt/bstos/linux-23/sysroots/x86_64-bstsdk-linux/usr/bin/aarch64-bst-linux/aarch64-bst-linux-strip",
    ],
    cxx_builtin_include_directories = [
        "/opt/bstos/linux-23/sysroots/aarch64-bst-linux/usr/include",
        "<TODO: /opt/bstos/linux-23/sysroots/aarch64-bst-linux/usr/include/c++/VERSION>",
        "/work/toolchains/a1000_linux/esr/fc_linux_pack/usr/include",
        "/work/toolchains/a1000_linux/bstos_2.3.5.4/sysroots/x86_64-bstsdk-linux/usr/lib/aarch64-bst-linux/gcc/aarch64-bst-linux/8.3.0/include",
        "/work/toolchains/a1000_linux/bstos_2.3.5.4/sysroots/x86_64-bstsdk-linux/usr/lib/aarch64-bst-linux/gcc/aarch64-bst-linux/8.3.0/include-fixed",
        "/work/toolchains/a1000_linux/bstos_2.3.5.4/sysroots/x86_64-bstsdk-linux/usr/lib/gcc/aarch64-bst-linux/8.3.0/include",
    ],
    builtin_sysroot = "/opt/bstos/linux-23/sysroots/aarch64-bst-linux",
    target_libc = "glibc",
)

cc_toolchain(
    name = "linux_aarch64_cc_toolchain",
    toolchain_identifier = "linux_aarch64_gnu",
    toolchain_config = ":linux_aarch64_toolchain_config",
    all_files = ":linux_aarch64_files",
    ar_files = ":linux_aarch64_files",
    compiler_files = ":linux_aarch64_files",
    dwp_files = ":linux_aarch64_files",
    linker_files = ":linux_aarch64_files",
    objcopy_files = ":linux_aarch64_files",
    strip_files = ":linux_aarch64_files",
)

toolchain(
    name = "linux_aarch64_toolchain",
    toolchain_type = "@bazel_tools//tools/cpp:toolchain_type",
    toolchain = ":linux_aarch64_cc_toolchain",
    target_compatible_with = [
        "@platforms//cpu:aarch64",
        "@platforms//os:linux",
    ],
)

# ========== QNX aarch64 ==========

filegroup(
    name = "qnx_aarch64_files",
    srcs = [],
)

aarch64_toolchain_config(
    name = "qnx_aarch64_toolchain_config",
    toolchain_identifier = "qnx_aarch64_gnu",
    target_system_name = "aarch64-unknown-nto-qnx",
    compiler = "gcc",
    tool_path_names = [
        "ar",
        "cpp",
        "gcc",
        "g++",
        "ld",
        "nm",
        "objcopy",
        "objdump",
        "strip",
    ],
    tool_path_paths = [
        "/work/toolchains/qnx710/qnx710/host/linux/x86_64/usr/bin/aarch64-unknown-nto-qnx7.1.0-ar",
        "/work/toolchains/qnx710/qnx710/host/linux/x86_64/usr/bin/aarch64-unknown-nto-qnx7.1.0-cpp",
        "/work/toolchains/qnx710/qnx710/host/linux/x86_64/usr/bin/aarch64-unknown-nto-qnx7.1.0-gcc",
        "/work/toolchains/qnx710/qnx710/host/linux/x86_64/usr/bin/aarch64-unknown-nto-qnx7.1.0-g++",
        "/work/toolchains/qnx710/qnx710/host/linux/x86_64/usr/bin/aarch64-unknown-nto-qnx7.1.0-ld",
        "/work/toolchains/qnx710/qnx710/host/linux/x86_64/usr/bin/aarch64-unknown-nto-qnx7.1.0-nm",
        "/work/toolchains/qnx710/qnx710/host/linux/x86_64/usr/bin/aarch64-unknown-nto-qnx7.1.0-objcopy",
        "/work/toolchains/qnx710/qnx710/host/linux/x86_64/usr/bin/aarch64-unknown-nto-qnx7.1.0-objdump",
        "/work/toolchains/qnx710/qnx710/host/linux/x86_64/usr/bin/aarch64-unknown-nto-qnx7.1.0-strip",
    ],

    cxx_builtin_include_directories = [
        "/work/toolchains/qnx710/qnx710/host/linux/x86_64/usr/lib/gcc/aarch64-unknown-nto-qnx7.1.0/8.3.0/include",
        "/work/toolchains/qnx710/qnx710/target/qnx7/usr/include/c++/v1",
        "/work/toolchains/qnx710/qnx710/target/qnx7/usr/include",
    ],

    builtin_sysroot = "/work/toolchains/qnx710/qnx710/target/qnx7",
    target_libc = "qnx",
)

cc_toolchain(
    name = "qnx_aarch64_cc_toolchain",
    toolchain_identifier = "qnx_aarch64_gnu",
    toolchain_config = ":qnx_aarch64_toolchain_config",
    all_files = ":qnx_aarch64_files",
    ar_files = ":qnx_aarch64_files",
    compiler_files = ":qnx_aarch64_files",
    dwp_files = ":qnx_aarch64_files",
    linker_files = ":qnx_aarch64_files",
    objcopy_files = ":qnx_aarch64_files",
    strip_files = ":qnx_aarch64_files",
)

toolchain(
    name = "qnx_aarch64_toolchain",
    toolchain_type = "@bazel_tools//tools/cpp:toolchain_type",
    toolchain = ":qnx_aarch64_cc_toolchain",
    target_compatible_with = [
        "@platforms//cpu:aarch64",
        "//platforms:qnx",
    ],
)
