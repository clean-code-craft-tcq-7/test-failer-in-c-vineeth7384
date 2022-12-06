#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "alert.h"

extern int alertFailureCount;

int TestNetworAlertStatus = 0;

// Stub function 
int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub shall return the status simulated in the test cases
    return TestNetworAlertStatus;
}


void testAlerter(float farenheit, int return_code)
{
    int alert_failure_count = alertFailureCount;
    TestNetworAlertStatus = return_code;

    // Test the function under test
    alertInCelcius(farenheit, networkAlertStub);

    // Check for the intended result
    if(return_code == 200)
    {
        assert(alertFailureCount == alert_failure_count);
    }
    else
    {
        assert(alertFailureCount == alert_failure_count + 1);
    }
}


