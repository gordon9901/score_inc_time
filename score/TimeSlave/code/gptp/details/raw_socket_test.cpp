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
#include "score/TimeSlave/code/gptp/details/network_identity.h"
#include "score/TimeSlave/code/gptp/details/raw_socket.h"

#include <gtest/gtest.h>

#include <time.h>
#include <cstring>

namespace score
{
namespace ts
{
namespace details
{

// ── RawSocket — closed-state guard paths ─────────────────────────────────────

TEST(RawSocketTest, DefaultConstruct_GetFd_ReturnsNegativeOne)
{
    RawSocket sock;
    EXPECT_EQ(sock.GetFd(), -1);
}

TEST(RawSocketTest, Close_WhenNotOpen_IsNoOp)
{
    RawSocket sock;
    EXPECT_NO_THROW(sock.Close());
    EXPECT_EQ(sock.GetFd(), -1);
}

TEST(RawSocketTest, EnableHwTimestamping_WhenNotOpen_ReturnsFalse)
{
    RawSocket sock;
    EXPECT_FALSE(sock.EnableHwTimestamping());
}

TEST(RawSocketTest, Recv_WhenNotOpen_ReturnsNegativeOne)
{
    RawSocket sock;
    std::uint8_t buf[64] = {};
    ::timespec hwts{};
    EXPECT_EQ(sock.Recv(buf, sizeof(buf), hwts, 0), -1);
}

TEST(RawSocketTest, Recv_NullBuf_ReturnsNegativeOne)
{
    RawSocket sock;
    ::timespec hwts{};
    EXPECT_EQ(sock.Recv(nullptr, 64U, hwts, 0), -1);
}

TEST(RawSocketTest, Recv_ZeroBufLen_ReturnsNegativeOne)
{
    RawSocket sock;
    std::uint8_t buf[1] = {};
    ::timespec hwts{};
    EXPECT_EQ(sock.Recv(buf, 0U, hwts, 0), -1);
}

TEST(RawSocketTest, Send_WhenNotOpen_ReturnsNegativeOne)
{
    RawSocket sock;
    const std::uint8_t data[14] = {};
    ::timespec hwts{};
    EXPECT_EQ(sock.Send(data, 14, hwts), -1);
}

TEST(RawSocketTest, Send_NullBuf_ReturnsNegativeOne)
{
    RawSocket sock;
    ::timespec hwts{};
    EXPECT_EQ(sock.Send(nullptr, 14, hwts), -1);
}

TEST(RawSocketTest, Send_ZeroLen_ReturnsNegativeOne)
{
    RawSocket sock;
    const std::uint8_t data[1] = {};
    ::timespec hwts{};
    EXPECT_EQ(sock.Send(data, 0, hwts), -1);
}

TEST(RawSocketTest, Send_NegativeLen_ReturnsNegativeOne)
{
    RawSocket sock;
    const std::uint8_t data[1] = {};
    ::timespec hwts{};
    EXPECT_EQ(sock.Send(data, -1, hwts), -1);
}

// ── RawSocket — invalid interface ────────────────────────────────────────────

TEST(RawSocketTest, Open_NonExistentInterface_ReturnsFalse)
{
    RawSocket sock;
    EXPECT_FALSE(sock.Open("nonexistent_eth_zzz"));
}

TEST(RawSocketTest, Open_NonExistentInterface_GetFdRemainsNegativeOne)
{
    RawSocket sock;
    (void)sock.Open("nonexistent_eth_zzz");
    EXPECT_EQ(sock.GetFd(), -1);
}

// ── NetworkIdentity ───────────────────────────────────────────────────────────

TEST(NetworkIdentityTest, GetClockIdentity_BeforeResolve_ReturnsZeroIdentity)
{
    NetworkIdentity ni;
    const ClockIdentity id = ni.GetClockIdentity();
    for (const std::uint8_t b : id.id)
    {
        EXPECT_EQ(b, 0U);
    }
}

TEST(NetworkIdentityTest, Resolve_NonExistentInterface_ReturnsFalse)
{
    NetworkIdentity ni;
    EXPECT_FALSE(ni.Resolve("nonexistent_eth_zzz"));
}

TEST(NetworkIdentityTest, Resolve_NonExistentInterface_GetClockIdentityRemainsZero)
{
    NetworkIdentity ni;
    (void)ni.Resolve("nonexistent_eth_zzz");
    const ClockIdentity id = ni.GetClockIdentity();
    for (const std::uint8_t b : id.id)
    {
        EXPECT_EQ(b, 0U);
    }
}

TEST(NetworkIdentityTest, Resolve_LoInterface_ReturnsTrue)
{
    // lo has MAC 00:00:00:00:00:00; the EUI-48→EUI-64 conversion inserts
    // 0xFF 0xFE at positions 3–4 regardless of the MAC value.
    NetworkIdentity ni;
    EXPECT_TRUE(ni.Resolve("lo"));
}

TEST(NetworkIdentityTest, GetClockIdentity_AfterResolveOnLo_HasFfFeBytes)
{
    NetworkIdentity ni;
    ASSERT_TRUE(ni.Resolve("lo"));
    const ClockIdentity id = ni.GetClockIdentity();
    // EUI-48 → EUI-64: bytes 3 and 4 must be 0xFF and 0xFE
    EXPECT_EQ(id.id[3], 0xFFU);
    EXPECT_EQ(id.id[4], 0xFEU);
}

TEST(NetworkIdentityTest, Resolve_CalledTwice_SecondCallSucceeds)
{
    NetworkIdentity ni;
    ASSERT_TRUE(ni.Resolve("lo"));
    EXPECT_TRUE(ni.Resolve("lo"));
}

}  // namespace details
}  // namespace ts
}  // namespace score
