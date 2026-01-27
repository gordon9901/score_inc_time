/*
 * @Author: chenhao.gao chenhao.gao@ecarxgroup.com
 * @Date: 2025-12-24 10:01:12
 * @LastEditors: chenhao.gao chenhao.gao@ecarxgroup.com
 * @LastEditTime: 2026-01-26 14:20:40
 */
#pragma once
#include <cstddef>
#include <string>

namespace score_time::ipc
{

    class ShmRegion final
    {
    public:
        ShmRegion() = default;
        ~ShmRegion();

        ShmRegion(const ShmRegion &) = delete;
        ShmRegion &operator=(const ShmRegion &) = delete;

        ShmRegion(ShmRegion &&other) noexcept;
        ShmRegion &operator=(ShmRegion &&other) noexcept;

        // create_or_open: true -> create if missing, set size; false -> open only.
        bool Open(const std::string &name, std::size_t size, bool create_or_open);
        void Close();

        void *Addr() const { return addr_; }
        std::size_t Size() const { return size_; }
        int Fd() const { return fd_; }
        bool Valid() const { return addr_ != nullptr; }

    private:
        std::string name_;
        int fd_ = -1;
        void *addr_ = nullptr;
        std::size_t size_ = 0;
    };

}
