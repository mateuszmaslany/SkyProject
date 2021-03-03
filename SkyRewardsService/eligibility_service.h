#ifndef ELIGIBILITY_SERVICE_H
#define ELIGIBILITY_SERVICE_H

#include "eligibility_result_enum.h"

class eligibility_service
{
public:
    eligibility_service();

    virtual ~eligibility_service();

    virtual eligibility_result is_eligible(unsigned int account_number) const;
};

#endif // ELIGIBILITY_SERVICE_H
