/*
 * @Author: chenhao.gao chenhao.gao@ecarxgroup.com
 * @Date: 2025-12-24 10:01:11
 * @LastEditors: chenhao.gao chenhao.gao@ecarxgroup.com
 * @LastEditTime: 2026-01-26 14:27:50
 */
#include <atomic>
#include <cstdlib>
#include <csignal>
#include <cstdio>
#include <cstring>
#include <unistd.h>

#include "time_sync_engine.hpp"
#include "config_loader.hpp"

static std::atomic<bool> g_exit{false};

static void signal_handler(int signum)
{
    if (signum == SIGTERM || signum == SIGINT)
        g_exit.store(true, std::memory_order_release);
}

static void init_signals()
{
    std::signal(SIGTERM, signal_handler);
    std::signal(SIGINT, signal_handler);
}

int main(int argc, char **argv)
{
    init_signals();

    tsyncd::EngineOptions opt;

    std::string config_path = "./tsyncd.conf";
    for (int i = 1; i < argc; ++i)
    {
        if (std::strcmp(argv[i], "--config") == 0 && i + 1 < argc)
        {
            config_path = argv[++i];
        }
    }

    tsyncd::LoadEngineOptionsFromFile(config_path, opt);

    tsyncd::TimeSyncEngine engine(opt);
    if (!engine.Start())
    {
        std::fprintf(stderr, "tsyncd: failed to start\n");
        return 1;
    }

    while (!g_exit.load(std::memory_order_acquire))
    {
        ::sleep(1);
    }

    engine.Stop();
    std::fprintf(stderr, "tsyncd: exit\n");
    return 0;
}
