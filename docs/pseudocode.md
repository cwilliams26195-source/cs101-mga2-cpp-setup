PROGRAM: Belize Travel & Activity Advisor System
START

    // 1. INPUT TRAVELER NAME
    PRINT "Enter Lead Traveler Name: "
    READ travelerName

    // 2. INPUT & DEFENSIVE VALIDATION: DESTINATION ZONE
    REPEAT
        PRINT "Select Destination Zone: [1] Coastal, [2] Inland, [3] Southern"
        READ destination
        IF destination < 1 OR destination > 3 THEN
            PRINT "[ERROR] Invalid selection. Enter 1, 2, or 3."
        ENDIF
    UNTIL destination >= 1 AND destination <= 3

    // 3. INPUT & DEFENSIVE VALIDATION: WEATHER FORECAST
    REPEAT
        PRINT "Select Weather: [1] Clear & Sunny, [2] Rainy, [3] Severe Storm"
        READ weather
        IF weather < 1 OR weather > 3 THEN
            PRINT "[ERROR] Invalid selection. Enter 1, 2, or 3."
        ENDIF
    UNTIL weather >= 1 AND weather <= 3

    // 4. INPUT & DEFENSIVE VALIDATION: DAILY BUDGET
    REPEAT
        PRINT "Enter Expected Daily Budget per Person ($ USD): "
        READ budget
        IF budget < 0.0 THEN
            PRINT "[ERROR] Invalid budget. Enter 0 or higher."
        ENDIF
    UNTIL budget >= 0.0

    // 5. BUDGET CATEGORIZATION (Else-If Ladder)
    IF budget < 75.00 THEN
        SET budgetTier = 1    // Backpacker / Economy
    ELSE IF budget <= 250.00 THEN
        SET budgetTier = 2    // Explorer / Moderate
    ELSE
        SET budgetTier = 3    // Luxury / Private Tour
    ENDIF

    // 6. INPUT & DEFENSIVE VALIDATION: ACTIVITY INTEREST
    REPEAT
        PRINT "Select Activity Interest: [A]dventure, [C]ulture, [R]elaxation"
        READ activity
        SET activity = CONVERT_TO_UPPERCASE(activity)
        IF activity != 'A' AND activity != 'C' AND activity != 'R' THEN
            PRINT "[ERROR] Invalid selection. Enter A, C, or R."
        ENDIF
    UNTIL activity == 'A' OR activity == 'C' OR activity == 'R'

    // 7. ALGORITHMIC DECISION ENGINE
    
    // Guard Clause 1 & 2: Evaluate Severe Weather Immediate Filter
    IF weather == 3 THEN
        IF destination == 1 THEN
            // Rule R-04
            SET recommendation = "HALT WATER TOURS: Port Authority small craft lockdown in effect."
            SET gearChecklist = "Emergency LED flashlight, waterproof storm jacket, battery power bank."
            SET logisticalTip = "Shelter in concrete accommodations; monitor NEMO radio updates."
        ELSE
            // Rule R-09
            SET recommendation = "ADVISORY: Flash flood warning for all river networks."
            SET gearChecklist = "High-intensity LED headlamp, water purification tablets, rain poncho."
            SET logisticalTip = "Suspend caving and river crossings; remain in urban centers."
        ENDIF
    ELSE
        // Primary Geographical Menu Routing (Switch Statement)
        SWITCH destination DO
            
            CASE 1: // Coastal / Cayes
                IF weather == 1 AND (budgetTier == 2 OR budgetTier == 3) AND activity == 'A' THEN
                    // Rule R-01
                    SET recommendation = "Hol Chan Marine Reserve Snorkeling / Scuba Dive Tour"
                    SET gearChecklist = "Reef-safe biodegradable sunscreen, rash guard, fins."
                    SET logisticalTip = "Book authorized tour guides with BTB license."
                ELSE IF weather == 1 AND budgetTier == 1 THEN
                    // Rule R-02
                    SET recommendation = "Caye Caulker 'Split' swimming & beach cycling"
                    SET gearChecklist = "Reusable water container, sun hat, UV polarized glasses."
                    SET logisticalTip = "Free public access at The Split; rent bicycles near main dock."
                ELSE IF weather == 2 AND (activity == 'C' OR activity == 'R') THEN
                    // Rule R-03
                    SET recommendation = "Traditional Garifuna drum making & culinary tasting"
                    SET gearChecklist = "Light windbreaker, waterproof dry-bag for mobile devices."
                    SET logisticalTip = "Indoors activity, protected from tropical squalls."
                ELSE
                    SET recommendation = "Coastal Beach Relaxation & Barrier Reef Sunset Cruise"
                    SET gearChecklist = "Polarized sunglasses, boat shoes, light linen shirt."
                    SET logisticalTip = "Water taxi transits running on regular schedules."
                ENDIF
                BREAK

            CASE 2: // Inland / Maya Heartland
                IF weather == 1 AND activity == 'A' THEN
                    // Rule R-05
                    SET recommendation = "Actun Tunichil Muknal (ATM) Cave Exploration"
                    SET gearChecklist = "Closed-toe trail shoes, quick-dry synthetic clothing, dry socks."
                    SET logisticalTip = "Mandatory licensed guide required. No cameras allowed."
                ELSE IF weather == 1 AND (budgetTier == 1 OR budgetTier == 2) AND activity == 'C' THEN
                    // Rule R-06
                    SET recommendation = "Self-guided tour of Xunantunich Mayan Temples"
                    SET gearChecklist = "Mosquito repellent, local ferry tip money, hydration pack."
                    SET logisticalTip = "Cross hand-crank ferry; open daily 8:00 AM to 4:00 PM."
                ELSE IF weather == 2 AND activity == 'A' THEN
                    // Rule R-07
                    SET recommendation = "Barton Creek Cave Canoe Expedition (covered canopy)"
                    SET gearChecklist = "Poncho, dry pack, headlamp with fresh alkaline batteries."
                    SET logisticalTip = "Covered cave passage shields travelers from rain."
                ELSE
                    SET recommendation = "San Ignacio Farmers Market & Cahal Pech Ruins Tour"
                    SET gearChecklist = "Walking shoes, sun hat, local currency (BZD)."
                    SET logisticalTip = "Farmers market is most active on Saturdays."
                ENDIF
                BREAK

            CASE 3: // Southern Rainforest
                IF budgetTier == 3 AND (activity == 'R' OR activity == 'A') THEN
                    // Rule R-08
                    SET recommendation = "Luxury Eco-Lodge birding canopy walk & cocoa tour"
                    SET gearChecklist = "Insect bite soothing cream, binoculars, moisture-wicking linen."
                    SET logisticalTip = "Early morning tours offer optimal birding opportunities."
                ELSE
                    SET recommendation = "Cockscomb Basin Wildlife Sanctuary Hike & Hopkins Garifuna Center"
                    SET gearChecklist = "Sturdy hiking boots, insect repellent with DEET, rain jacket."
                    SET logisticalTip = "Register at ranger station prior to entering trail networks."
                ENDIF
                BREAK
                
        ENDSWITCH
    ENDIF

    // 8. DISPLAY FORMATTED OUTPUT
    PRINT "================================================================"
    PRINT "                 CURATED BELIZE TRAVEL ITINERARY                "
    PRINT "================================================================"
    PRINT "Traveler Name    : " + travelerName
    PRINT "Destination      : " + destination
    PRINT "Weather Profile  : " + weather
    PRINT "Budget Tier      : " + budgetTier + " ($" + budget + " USD/day)"
    PRINT "Selected Focus   : " + activity
    PRINT "----------------------------------------------------------------"
    PRINT "RECOMMENDED EXPERIENCE:"
    PRINT ">> " + recommendation
    PRINT "RECOMMENDED GEAR CHECKLIST:"
    PRINT " * " + gearChecklist
    PRINT "LOGISTICAL ADVISORY:"
    PRINT " * " + logisticalTip
    PRINT "================================================================"

END