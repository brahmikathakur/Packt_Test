# Packt_Test
Packt | Performance Test Engineer

Hi Packt Team,

Greetings!!!

I have used Micro focus load runner VUgen for recording script (BlazeDemo), Load runner controller  for creating scenario and executing test & Load runner analysis for reporting.

**SCRIPT** : - It contains only two pages.
            1. Blazedemo landing page
            2. Find flight page
         - Parameterized the static values
         - in above two pages no dynamic value got caputed, else would have used correlation for it.

**SCENARIO** : - Created scenario as per the requirement. 
           - Added a duration on 5mins, when there were 30 users in the system.
           - Ramp down all the users simultaneously.

**RESULTS** : - Attached a detailed autogenerated load runner report with all the required graphs and stats.

**OBSERVATIONS** :
- Average response time for homepage was above 1sec but for the find_flights page remains below 1sec.
- At the start of the test, a spike of 2.1sec was observed. Later it was stable through out the test.
- TPS and throughput was increasing simultaneosly with the users.
- No major failure were observed. Only 9 transactions failed with "Failed to connect to server error : Connection Timeout". This can be handled by adding some session pacing.
- Which indicates, the site can handle more load. 30 users is not the breakpoint for the site.
