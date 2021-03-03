#ifndef REWARDS_SERVICE_TESTS_H
#define REWARDS_SERVICE_TESTS_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "eligibility_service_mock.h"

#include "..\SkyRewardsService\eligibility_service.h"
#include "..\SkyRewardsService\customer.h"
#include "..\SkyRewardsService\exceptions.h"
#include "..\SkyRewardsService\rewards_service.h"
using namespace testing;

TEST(RewardsService, CheckForRewardsReturnsExpectedRewards)
{
    std::shared_ptr<eligibility_service_mock> mock(
        std::make_shared<eligibility_service_mock>());

    rewards_service rs(mock);

    QVector<channel_name> const channels = {
        channel_name::SPORTS,
        channel_name::KIDS,
        channel_name::MUSIC,
        channel_name::NEWS,
        channel_name::MOVIES};

    QVector<reward_name> const rewards = {
        reward_name::CHAMPIONS_LEAGUE_FINAL_TICKET,
        reward_name::KARAOKE_PRO_MICROPHONE,
        reward_name::PIRATES_OF_THE_CARIBBEAN_COLLECTION};

    unsigned int const account_number = 1234;

    rewards_response const expected_response(rewards, true);

    EXPECT_CALL(*mock, is_eligible(_))
            .WillOnce(Return(eligibility_result::CUSTOMER_ELIGIBLE));

    rewards_response const response = rs.check_for_rewards(account_number, channels);

    EXPECT_EQ(expected_response.is_account_number_valid(), response.is_account_number_valid());
    EXPECT_EQ(expected_response.get_rewards(), response.get_rewards());
}

TEST(RewardsService, CheckForRewardsReturnsNoRewardsForUnentitledChannels)
{
    std::shared_ptr<eligibility_service_mock> mock(
        std::make_shared<eligibility_service_mock>());

    rewards_service rs(mock);

    QVector<channel_name> const channels = {
        channel_name::KIDS,
        channel_name::NEWS};

    QVector<reward_name> const rewards = {};

    unsigned int const account_number = 1234;

    rewards_response const expected_response(rewards, true);

    EXPECT_CALL(*mock, is_eligible(_))
            .WillOnce(Return(eligibility_result::CUSTOMER_ELIGIBLE));

    rewards_response const response = rs.check_for_rewards(account_number, channels);

    EXPECT_EQ(expected_response.is_account_number_valid(), response.is_account_number_valid());
    EXPECT_EQ(expected_response.get_rewards(), response.get_rewards());
}

TEST(RewardsService, CheckForRewardsReturnsNoRewardsForEmptyVectorOfChannels)
{
    std::shared_ptr<eligibility_service_mock> mock(
        std::make_shared<eligibility_service_mock>());

    rewards_service rs(mock);

    QVector<channel_name> const channels = {};

    QVector<reward_name> const rewards = {};

    unsigned int const account_number = 1234;

    rewards_response const expected_response(rewards, true);

    EXPECT_CALL(*mock, is_eligible(_))
            .WillOnce(Return(eligibility_result::CUSTOMER_ELIGIBLE));

    rewards_response const response = rs.check_for_rewards(account_number, channels);

    EXPECT_EQ(expected_response.is_account_number_valid(), response.is_account_number_valid());
    EXPECT_EQ(expected_response.get_rewards(), response.get_rewards());
}

TEST(RewardsService, CheckForRewardsReturnsNoRewardsForInentitledAccountNumber)
{
    std::shared_ptr<eligibility_service_mock> mock(
        std::make_shared<eligibility_service_mock>());

    rewards_service rs(mock);

    QVector<channel_name> const channels = {
        channel_name::SPORTS,
        channel_name::KIDS,
        channel_name::MUSIC,
        channel_name::NEWS,
        channel_name::MOVIES};

    QVector<reward_name> const rewards = {};

    unsigned int const account_number = 1234;

    rewards_response const expected_response(rewards, true);

    EXPECT_CALL(*mock, is_eligible(_))
            .WillOnce(Return(eligibility_result::CUSTOMER_INELIGIBLE));

    rewards_response const response = rs.check_for_rewards(account_number, channels);

    EXPECT_EQ(expected_response.is_account_number_valid(), response.is_account_number_valid());
    EXPECT_EQ(expected_response.get_rewards(), response.get_rewards());
}

TEST(RewardsService, CheckForRewardsReturnsNoRewardsWhenEligibilityServiceThrowsTechnicalFailureException)
{
    std::shared_ptr<eligibility_service_mock> mock(
        std::make_shared<eligibility_service_mock>());

    rewards_service rs(mock);

    QVector<channel_name> const channels = {
        channel_name::SPORTS,
        channel_name::KIDS,
        channel_name::MUSIC};

    QVector<reward_name> const rewards = {};

    unsigned int const account_number = 1234;

    rewards_response const expected_response(rewards, true);

    EXPECT_CALL(*mock, is_eligible(_))
            .WillOnce(Throw(technical_failure_exception("Technical Failure")));

    rewards_response const response = rs.check_for_rewards(account_number, channels);

    EXPECT_EQ(expected_response.is_account_number_valid(), response.is_account_number_valid());
    EXPECT_EQ(expected_response.get_rewards(), response.get_rewards());
}

TEST(RewardsService,
     CheckForRewardsReturnsNoRewardsAndInvalidAccountNumerWhenEligibilityServiceThrowsInvalidAccountNumberException)
{
    std::shared_ptr<eligibility_service_mock> mock(
        std::make_shared<eligibility_service_mock>());

    rewards_service rs(mock);

    QVector<channel_name> const channels = {
        channel_name::SPORTS,
        channel_name::KIDS,
        channel_name::MUSIC};

    QVector<reward_name> const rewards = {};

    unsigned int const account_number = 1234;

    rewards_response const expected_response(rewards, false);

    EXPECT_CALL(*mock, is_eligible(_))
            .WillOnce(Throw(invalid_account_number_exception("Invalid Account Number")));

    rewards_response const response = rs.check_for_rewards(account_number, channels);

    EXPECT_EQ(expected_response.is_account_number_valid(), response.is_account_number_valid());
    EXPECT_EQ(expected_response.get_rewards(), response.get_rewards());
}

#endif // REWARDS_SERVICE_TESTS_H
