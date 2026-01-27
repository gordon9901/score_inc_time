load("@rules_cc//cc:cc_toolchain_config_lib.bzl", "tool_path")

def _aarch64_toolchain_config_impl(ctx):
    names = ctx.attr.tool_path_names
    paths = ctx.attr.tool_path_paths
    if len(names) != len(paths):
        fail("tool_path_names and tool_path_paths length mismatch: %d vs %d" % (len(names), len(paths)))

    tool_paths = []
    for i in range(len(names)):
        tool_paths.append(tool_path(name = names[i], path = paths[i]))

    return [cc_common.create_cc_toolchain_config_info(
        ctx = ctx,
        toolchain_identifier = ctx.attr.toolchain_identifier,
        host_system_name = "local",
        target_system_name = ctx.attr.target_system_name,
        target_cpu = "aarch64",
        target_libc = ctx.attr.target_libc,
        compiler = ctx.attr.compiler,
        abi_version = ctx.attr.abi_version,
        abi_libc_version = ctx.attr.abi_libc_version,
        tool_paths = tool_paths,
        cxx_builtin_include_directories = ctx.attr.cxx_builtin_include_directories,
        builtin_sysroot = ctx.attr.builtin_sysroot,
        features = [],
        action_configs = [],
    )]

aarch64_toolchain_config = rule(
    implementation = _aarch64_toolchain_config_impl,
    attrs = {
        "toolchain_identifier": attr.string(mandatory = True),
        "target_system_name": attr.string(mandatory = True),
        "compiler": attr.string(mandatory = True),
        "tool_path_names": attr.string_list(mandatory = True),
        "tool_path_paths": attr.string_list(mandatory = True),
        "cxx_builtin_include_directories": attr.string_list(mandatory = True),
        "builtin_sysroot": attr.string(default = ""),
        "target_libc": attr.string(default = "unknown"),
        "abi_version": attr.string(default = "unknown"),
        "abi_libc_version": attr.string(default = "unknown"),
    },
    provides = [CcToolchainConfigInfo],
)
