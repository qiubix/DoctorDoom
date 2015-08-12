#include "PlaceDescriptionService.h"
#include "Http.h"
#include "AddressExtractor.h"
#include "Address.h"
#include <string>

using namespace std;

PlaceDescriptionService::PlaceDescriptionService(Http* http) : http_(http) {}

string PlaceDescriptionService::summaryDescription(const string& latitude, const string& longitude) const {
  auto request = createGetRequestUrl(latitude, longitude);
  auto response = get(request);
  return summaryDescription(response);
}

string PlaceDescriptionService::summaryDescription(const string& response) const {
  AddressExtractor extractor;
  auto address = extractor.addressFrom(response);

  return address.summaryDescription();
}

string PlaceDescriptionService::createGetRequestUrl(const string& latitude, const string& longitude) const {
  string urlStart{"http://open.mapquestapi.com/nominatim/v1/reverse?format=json&"};
  return urlStart + "lat=" + latitude + "&lon=" + longitude;
}

string PlaceDescriptionService::get(const string& request) const {
  return http_->get(request);
}
