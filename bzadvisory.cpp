#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string name;
    int dest = 0, weather = 0;
    double budget = -1.0;
    char activity = ' ';

    cout << "================================================================\n";
    cout << "             BELIZE TRAVEL & ACTIVITY ADVISOR SYSTEM              \n";
    cout << "               Ministry of Tourism & Civil Aviation             \n";
    cout << "================================================================\n\n";

    cout << "Enter Lead Traveler Name: ";
    getline(cin >> ws, name);

    cout << "\nSelect Destination Zone:\n";
    cout << "  [1] Coastal / Cayes (Ambergris Caye, Caye Caulker, Placencia)\n";
    cout << "  [2] Inland Heartland (Cayo District, San Ignacio, Pine Ridge)\n";
    cout << "  [3] Southern Rainforest (Stann Creek, Toledo, Hopkins)\n";
    cout << "Select Destination [1-3]: ";
    while (!(cin >> dest) || dest < 1 || dest > 3) {
        cout << "[ERROR] Invalid selection. Enter 1, 2, or 3: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout << "\nCurrent Weather Forecast:\n";
    cout << "  [1] Clear, Sunny Tropical\n";
    cout << "  [2] Intermittent Rain / Cloud Cover\n";
    cout << "  [3] Severe Weather / Small Craft Advisory\n";
    cout << "Select Weather Condition [1-3]: ";
    while (!(cin >> weather) || weather < 1 || weather > 3) {
        cout << "[ERROR] Invalid selection. Enter 1, 2, or 3: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout << "\nEnter Expected Daily Budget per Person ($ USD): ";
    while (!(cin >> budget) || budget < 0.0) {
        cout << "[ERROR] Invalid budget. Enter 0 or higher: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    int budgetTier = 0;
    string tierLabel = "";
    if (budget < 75.00) {
        budgetTier = 1;
        tierLabel = "Tier 1 (Backpacker / Economy)";
    } else if (budget <= 250.00) {
        budgetTier = 2;
        tierLabel = "Tier 2 (Explorer / Moderate)";
    } else {
        budgetTier = 3;
        tierLabel = "Tier 3 (Luxury / Private)";
    }

    cout << "\nPrimary Activity Interest ([A]dventure, [C]ulture, [R]elaxation): ";
    cin >> activity;
    activity = toupper(activity);
    while (activity != 'A' && activity != 'C' && activity != 'R') {
        cout << "[ERROR] Invalid selection. Enter A, C, or R: ";
        cin >> activity;
        activity = toupper(activity);
    }

    string destStr = (dest == 1) ? "Coastal / Cayes" : (dest == 2) ? "Inland Heartland" : "Southern Rainforest";
    string weatherStr = (weather == 1) ? "Clear, Sunny Tropical" : (weather == 2) ? "Rainy / Tropical Squall" : "Severe Weather Advisory";
    string focusStr = (activity == 'A') ? "Adventure & Marine Expeditions" : (activity == 'C') ? "Cultural Tours & Heritage" : "Relaxation & Leisure";

    string rec = "", gear = "", tips = "";

    
    if (weather == 3) {
        if (dest == 1) { 
            rec = "HALT WATER TOURS: Port Authority small craft lockdown in effect.";
            gear = "Emergency LED flashlight, waterproof storm jacket, battery power bank.";
            tips = "Shelter in concrete accommodations; monitor NEMO radio updates.";
        } else { 
            rec = "ADVISORY: Flash flood warning for all river networks.";
            gear = "High-intensity LED headlamp, water purification tablets, rain poncho.";
            tips = "Suspend caving and river crossings; remain in urban centers.";
        }
    } 
    else {
        switch (dest) {
            case 1: 
                if (weather == 1 && (budgetTier == 2 || budgetTier == 3) && activity == 'A') { // R-01
                    rec = "Hol Chan Marine Reserve Snorkeling / Scuba Dive Tour";
                    gear = "Reef-safe biodegradable sunscreen, rash guard, fins.";
                    tips = "Book authorized tour guides with BTB license.";
                } else if (weather == 1 && budgetTier == 1) { // R-02
                    rec = "Caye Caulker \"Split\" swimming & beach cycling";
                    gear = "Reusable water container, sun hat, UV polarized glasses.";
                    tips = "Free access at The Split; rent bicycles near main dock.";
                } else if (weather == 2 && (activity == 'C' || activity == 'R')) { // R-03
                    rec = "Traditional Garifuna drum making & culinary tasting";
                    gear = "Light windbreaker, waterproof dry-bag for mobile devices.";
                    tips = "Indoors activity, protected from tropical squalls.";
                } else {
                    rec = "Coastal Beach Relaxation & Barrier Reef Sunset Cruise";
                    gear = "Polarized sunglasses, boat shoes, light linen shirt.";
                    tips = "Water taxi transits running on regular schedules.";
                }
                break;

            case 2: // Inland / Maya Heartland
                if (weather == 1 && activity == 'A') { // R-05
                    rec = "Actun Tunichil Muknal (ATM) Cave Exploration";
                    gear = "Closed-toe trail shoes, quick-dry synthetic clothing, dry socks.";
                    tips = "Mandatory licensed guide required. No cameras allowed.";
                } else if (weather == 1 && (budgetTier == 1 || budgetTier == 2) && activity == 'C') { // R-06
                    rec = "Self-guided tour of Xunantunich Mayan Temples";
                    gear = "Mosquito repellent, local ferry tip money, hydration pack.";
                    tips = "Cross hand-crank ferry; open daily 8:00 AM to 4:00 PM.";
                } else if (weather == 2 && activity == 'A') { // R-07
                    rec = "Barton Creek Cave Canoe Expedition (covered canopy)";
                    gear = "Poncho, dry pack, headlamp with fresh alkaline batteries.";
                    tips = "Covered cave passage shields travelers from rain.";
                } else {
                    rec = "San Ignacio Farmers Market & Cahal Pech Ruins Tour";
                    gear = "Walking shoes, sun hat, local currency (BZD).";
                    tips = "Farmers market is most active on Saturdays.";
                }
                break;

            case 3:
                if (budgetTier == 3 && (activity == 'R' || activity == 'A')) { // R-08
                    rec = "Luxury Eco-Lodge birding canopy walk & cocoa tour";
                    gear = "Insect bite soothing cream, binoculars, moisture-wicking linen.";
                    tips = "Early morning tours offer optimal birding opportunities.";
                } else {
                    rec = "Cockscomb Basin Wildlife Sanctuary Hike & Hopkins Garifuna Center";
                    gear = "Sturdy hiking boots, insect repellent with DEET, rain jacket.";
                    tips = "Register at ranger station prior to entering trail networks.";
                }
                break;
        }
    }

    cout << "\n================================================================\n";
    if (weather == 3) {
        cout << "            *** SPECIAL WEATHER WARNING ADVISORY ***            \n";
    } else {
        cout << "                 CURATED BELIZE TRAVEL ITINERARY                \n";
    }
    cout << "================================================================\n";
    cout << "Traveler Name    : " << name << "\n";
    cout << "Destination      : " << destStr << "\n";
    cout << "Weather Profile  : " << weatherStr << "\n";
    cout << "Budget Tier      : " << tierLabel << " ($" << budget << " USD/day)\n";
    cout << "Selected Focus   : " << focusStr << "\n";
    cout << "----------------------------------------------------------------\n";
    cout << "RECOMMENDED EXPERIENCE:\n>> " << rec << "\n\n";
    cout << "RECOMMENDED GEAR CHECKLIST:\n * " << gear << "\n\n";
    cout << "LOGISTICAL ADVISORY:\n * " << tips << "\n";
    cout << "================================================================\n";

    return 0;
}