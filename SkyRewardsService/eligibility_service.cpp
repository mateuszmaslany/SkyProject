#include "eligibility_service.h"

#include <QDateTime>

eligibility_service::eligibility_service()
{

}

eligibility_service::~eligibility_service()
{

}

eligibility_result eligibility_service::is_eligible(unsigned int account_number) const
{
    Q_UNUSED(account_number)

    return (QDateTime::currentSecsSinceEpoch() % 2)?
                eligibility_result::CUSTOMER_ELIGIBLE : eligibility_result::CUSTOMER_INELIGIBLE;
}
