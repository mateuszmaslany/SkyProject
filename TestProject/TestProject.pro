include(gtest_dependency.pri)

QT += core testlib
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread

HEADERS += \
        eligibility_service_mock.h \
        ..\SkyRewardsService\channel_name_enum.h \
        ..\SkyRewardsService\customer.h \
        ..\SkyRewardsService\eligibility_result_enum.h \
        ..\SkyRewardsService\eligibility_service.h \
        ..\SkyRewardsService\exceptions.h \
        ..\SkyRewardsService\reward_name_enum.h \
        ..\SkyRewardsService\rewards_response.h \
        ..\SkyRewardsService\rewards_service.h \
        rewards_service_tests.h

SOURCES += \
        main.cpp \
        ..\SkyRewardsService\customer.cpp \
        ..\SkyRewardsService\eligibility_service.cpp \
        ..\SkyRewardsService\rewards_response.cpp \
        ..\SkyRewardsService\rewards_service.cpp
