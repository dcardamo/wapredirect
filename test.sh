#!/bin/sh
echo
echo "Testing without HTTP_USER_AGENT set, should give htmlURL"
echo "----------------------------------------------------------------------"
unset HTTP_USER_AGENT
./wapredir.cgi
echo "----------------------------------------------------------------------"
echo
echo "Testing with HTTP_USER_AGENT set to Mozilla.  Should be htmlURL"
echo "----------------------------------------------------------------------"
export HTTP_USER_AGENT="Mozilla"
./wapredir.cgi
echo "----------------------------------------------------------------------"
echo
echo "Testing with HTTP_USER_AGENT set to Phone.  Should be wapURL"
echo "----------------------------------------------------------------------"
export HTTP_USER_AGENT="Phone"
./wapredir.cgi
echo "----------------------------------------------------------------------"
echo
