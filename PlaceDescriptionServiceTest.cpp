#include "gmock/gmock.h"

#include "PlaceDescriptionService.h"
#include "Http.h"

using namespace std;
using namespace testing;

class APlaceDescriptionService: public Test {
public:
  static const string ValidLatitude;
  static const string ValidLongitude;
};

const string APlaceDescriptionService::ValidLatitude("38.005");
const string APlaceDescriptionService::ValidLongitude("-104.44");

class HttpStub: public Http {
public:
};

TEST_F(APlaceDescriptionService, MakesHttpRequestToObtainAddress) {
}
