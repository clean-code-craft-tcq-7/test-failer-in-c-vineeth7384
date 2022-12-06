#include <stdio.h>
#include <assert.h>
#include "alert.h"
#include "Unittest_alert.h"

int alertFailureCount = 0;

float ConvertFaranheitToCelcius(float farenheit)
{
    return (farenheit - 32) * 5 / 9;
}

void alertInCelcius(float farenheit, int (*networkAlert_fptr)(float)) 
{
    float celcius = ConvertFaranheitToCelcius(farenheit);
    int returnCode = networkAlert_fptr(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}

int main() {
     testAlerter(97.6, 200);
    testAlerter(33.2, 410);
    testAlerter(11.54, 500);
    printf("All is well (maybe!)\n");
    return 0;
}
