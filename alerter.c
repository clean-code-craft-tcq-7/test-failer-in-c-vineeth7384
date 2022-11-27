#include <stdio.h>
#include <assert.h>
#include"UnitTest_config.h"

#define UNIT_TEST TRUE

int alertFailureCount = 0;
int NetworAlertStatus_Test =0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return NetworAlertStatus_Test;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    #ifdef UNIT_TEST
    int returnCode = networkAlertStub(celcius);
    #else
    int returnCode = networkAlert(celcius);
    #endif
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    printf("%d alerts failed.\n", alertFailureCount);
    NetworAlertStatus_Test = 500;
    alertInCelcius(400.5);
    assert(alertFailureCount == 1);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
