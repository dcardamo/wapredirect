#!/usr/bin/perl -w
use strict;

my $wapUrl = "http://hld.ca/email/wap";
my $htmlUrl = "http://hld.ca/index.shtml";

my @wapAgents = qw(Phone UP);


my $redir = "html";

#print "Content-type: text/html\n\n";
#foreach my $key (keys %ENV) {
#    print $key;
#}

foreach my $agent (@wapAgents) {
    if ($ENV{HTTP_USER_AGENT} =~ /$agent/) {
        $redir = 'wap';
        last;
    }
}

if ($redir eq 'wap') {
    print "Location: $wapUrl\n\n";
    print "Content-type: text/vnd.wap.wml\n\n";
}

else {
    print "Location: $htmlUrl\n\n";
}
