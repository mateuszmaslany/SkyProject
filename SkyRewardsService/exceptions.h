#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <QString>

class technical_failure_exception : public std::exception
{
public:
    explicit technical_failure_exception(QString const& msg) :
        msg_(msg)
    {}

    virtual const char* what() const noexcept {
           return msg_.toStdString().c_str();
    }

protected:
    QString const msg_;
};


class invalid_account_number_exception : public std::exception
{
public:
    explicit invalid_account_number_exception(QString const& msg) :
        msg_(msg)
    {}

    virtual const char* what() const noexcept {
           return msg_.toStdString().c_str();
    }

protected:
    QString const msg_;
};
#endif // EXCEPTIONS_H
