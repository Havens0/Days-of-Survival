//This is my first C++ project, a text-based adventure game called "Days of Survival".

#include <iostream>
#include <limits>
#include <chrono>
#include <thread>
using namespace std;

void print(const string& text, int delay = 60) {
    for (char c : text) {
        cout << c << flush;
        std::this_thread::sleep_for(chrono::milliseconds(delay));
    }
}

int main() {
    int choice;
    int scene = 0; // Controls the current scene
    int trust = 0; // Trust level with the group
    bool alive = true;

    const char YouDied[] = R"(
__   _______ _   _  ______ _____ ___________ 
\ \ / /  _  | | | | |  _  \_   _|  ___|  _  \
 \ V /| | | | | | | | | | | | | | |__ | | | |
  \ / | | | | | | | | | | | | | |  __|| | | |
  | | \ \_/ / |_| | | |/ / _| |_| |___| |/ / 
  \_/  \___/ \___/  |___/  \___/\____/|___/  
)";
    const char YouLive1[] = R"(
__   _______ _   _        _     _____ _   _ _____      
\ \ / /  _  | | | |      | |   |_   _| | | |  ___|     
 \ V /| | | | | | |      | |     | | | | | | |__       
  \ / | | | | | | |      | |     | | | | | |  __|      
  | | \ \_/ / |_| |      | |_____| |_\ \_/ / |____ _ _ 
  \_/  \___/ \___/       \_____/\___/ \___/\____(_|_|_)";

  const char YouLive2[] = R"(
__   _______ _   _    _     _____ _   _ _____ _ _ _ 
\ \ / /  _  | | | |  | |   |_   _| | | |  ___| | | |
 \ V /| | | | | | |  | |     | | | | | | |__ | | | |
  \ / | | | | | | |  | |     | | | | | |  __|| | | |
  | | \ \_/ / |_| |  | |_____| |_\ \_/ / |___|_|_|_|
  \_/  \___/ \___/   \_____/\___/ \___/\____/(_|_|_)";

   // --- Título animado ---
    print("-----------------------------------------\n", 10);
    print("     D A Y S   O F   S U R V I V A L\n", 30);
    print("-----------------------------------------\n\n", 10);
    this_thread::sleep_for(chrono::milliseconds(500));

    while (alive) {
        // --- Scene 0: Introduction ---
        if (scene == 0) {
            print("\nYou wake up in your bed after an afternoon nap.\n");
            print("You hear sirens and chaos in the streets outside. Curiosity urges you to investigate.\n");
            print("What do you do?\n");
            print("1) Go outside and see what's happening.\n");
            print("2) Look up news online.\n");
            print("3) Call your friend Alex.\n");
            print("> ");
            cin >> choice;

            if (!cin) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

            if (choice == 1) scene = 1;
            else if (choice == 2) scene = 2;
            else if (choice == 3) scene = 3;
            else print("Invalid choice.\n");
        }

        // --- Scene 1: Go outside ---
        else if (scene == 1) {
            print("\nYou go outside and see panic and chaos. People seem to be running away from something.\n");
            print("Authorities are present, but they seem overwhelmed.\n");
            print("Do you:\n");
            print("1) Go back inside and lock the door.\n");
            print("2) Go towards the chaos because you're very brave (Or very stupid)\n");
            print("> ");
            cin >> choice;

            if (!cin) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

            if (choice == 1) {
                print("You go back inside and lock the door. Luckily, you made your monthly grocery run yesterday.\n");
                scene = 0; // Go back to introduction
            }
            else if (choice == 2) {
                    print("You walk straight to where people are running from, like a hero in a movie. (Or a real world lunatic)\n");
                    print("You see 3 men running towards you, looking very angry and definitely not in their right minds.\n");
                    print("Apparently, you lack the common sense of a normal person, so you don't think to run away.\n");
                    print("Turns out, they were 'zombies'. They knock you down and munch you to death.\n");
                    print(string(YouDied) + "\n");
                    return 0;
            }
            else print("Invalid choice.\n");
        }

        // --- Scene 2: Look up news ---
        else if (scene == 2) {
            print("\nYou grab your phone. Official news sites are slow to update.\n");
            print("Social media, however, is exploding with videos of people attacking each other.\n");
            print("Some people are calling it a 'zombie outbreak', but... Is that even possible?\n");
            print("Your phone rings — it's your friend Alex, who lives nearby.\n");
            print("Do you:\n");
            print("1) Answer the call.\n");
            print("2) Ignore it and keep looking for news.\n");
            print("> ");
            cin >> choice;

            if (!cin) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

            if (choice == 1) scene = 3; // leads to the Alex conversation
            else if (choice == 2) {
                print("You ignore the call. Moments later, someone bangs on your door.\n");
                print("It's Alex. He yells: 'Open up! It's me!'\n");
                scene = 4; // leads to Alex arriving anyway
            }
            else print("Invalid choice.\n");
        }

        // --- Scene 3: Call Alex ---
        else if (scene == 3) {
                print("Your friend Alex starts spitting info almost immediately.\n");
                print("'Dude, have you seen the videos? It's a zombie outbreak! They're everywhere in the city!'\n");
                print("'We can make a safehouse at your place, it's got a good view of the street and we can reinforce the gates!'\n");
                print("(You don't know if he's very nervous or actually excited. You know him for being an FPS gaming nerd)\n");
                print("Do you:\n");
                print("1) Agree to meet him and fortify your apartment\n");
                print("2) Make static noises and pretend your phone has a bad connection\n");
                print("> ");
                cin >> choice;

            if (!cin) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

            if (choice == 1) {
                print("'I'm already on my way!' Alex says and hangs up.\n");
                scene = 4;
            }
            else if (choice == 2) {
                print("Alex doesn't buy it. 'Cut the crap, I'm heading over now!'\n");
                scene = 4;
            }
            else print("Invalid choice.\n");
        }

        // --- Scene 4: Alex arrives ---
        else if (scene == 4) {
            print("\nA few minutes later, Alex bursts through the door.\n");
            print("He looks like an unlockable character from a video game.\n");
            print("He drops a military backpack on your table.\n");
            print("Inside: a first aid kit, flashlight, canned food, and a crowbar.\n");
            print("He then opens a gym bag and it has special hardened clothes, two pistols with extra magazines, and a baseball bat.\n");
            print("Do you:\n");
            print("1) Reinforce the apartment.\n");
            print("2) Suggest leaving the city immediately.\n");
            print("> ");
            cin >> choice;

            if (!cin) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

            if (choice == 1) scene = 5; // defense branch
            else if (choice == 2) scene = 6; // escape branch
            else print("Invalid choice.\n");
        }

        // --- Scene 5: Fortify the apartment ---
        else if (scene == 5) {
            print("\nYou both start barricading doors and windows with furniture.\n");
            print("Hours pass. The city burns outside. The night is silent... too silent.\n");
            print("Suddenly, you hear gunshots in the street.\n");
            print("You wonder if it's another survivor in danger...\n");
            print("As you peek out the window, you do see a couple survivors running for their lives...\n");
            print("But what's chasing them surprises you... It's a group of military personnel!\n");
            print("As they run away, the military men shoot them on their backs...\n");
            print("You're both in shock. You hear a radio transmission:\n");
            print("'All units, contain the outbreak at all costs. No one is to leave the city.'\n");
            print("The situation is worse than you thought.\n");
            print("Do you:\n");
            print("1) Stay inside and wait for the situation to change.\n");
            print("2) Try to escape the city while you still can.\n");
            print("> ");
            cin >> choice;

            if (!cin) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

            if (choice == 1) {
                print("\nYou decide to stay put. Another day passes, and you hear more gunshots outside.\n");
                print("You can tell that zombies and the military are clashing frequently now.\n");
                print("Suddenly, there's a blackout. You hear explosions nearby.\n");
                print("There's various explosions around, and then, a loud explosion right outside your building.\n");
                print("Car alarms go off in your building parking lot. Zombies are gathering outside, attracted by the noise.\n");
                print("You and Alex prepare to defend yourselves, but there are too many.\n");
                print("Alex says: 'The gate won't hold. We have to make a run for it!'\n");
                print("Do you:\n");
                print("1) Make a run for it with Alex.\n");
                print("2) Hope the gate holds and stay inside.\n");
                print("> ");
                cin >> choice;

                if (!cin) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

                if (choice == 1) scene = 7; // Make a run for it
                else if (choice == 2) {
                    print("\nThe gate collapses under the weight of the zombies.\n");
                    print("They swarm in, before you can react.\n");
                    print("In a matter of seconds, you and Alex are ripped apart.\n");
                    print(string(YouDied) + "\n");
        }
                else print("Invalid choice.\n");
            }
            else if (choice == 2) scene = 6; // Escape branch
            else print("Invalid choice.\n");
        }

        // --- Scene 6: Escape branch ---
        else if (scene == 6) {
            print("\nYou convince Alex to leave. You both pack essentials and sneak out.\n");
            print("The streets are chaos, but you manage to reach Alex's car.\n");
            print("You try to drive away, but there's barricades and abandoned vehicles blocking the road.\n");
            print("You hear sirens in the distance... Maybe the authorities are finally responding.\n");
            print("Do you:\n");
            print("1) Go towards the sirens and try to get help.\n");
            print("2) Keep going on foot.\n");
            print("> ");
            cin >> choice;

            if (!cin) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

            if (choice == 1) {
                print("\nThe sirens come from the local hospital. You run towards the hospital.\n");
                print("When you get there, no one is left. The place is overrun.\n");
                print("Zombies notice you and start to surround you.\n");
                print("You flee as fast as you can, but they are still chasing you.\n");
                print("Alex points to a grocery store. 'We can hide there!'\n");
                print("You both manage to get inside, and see the zombies pass by the store...\n");
                print("What you didn't see, was the store owner, who was also hiding inside, armed and in fear...\n");
                print("As you're still focused on the zombies outside, the owner doesn't hesitate to shoot you both.\n");
                print(string(YouDied) + "\n");
                alive = false;
            }
            else if (choice == 2) {
                print("\nYou manage to defend yourselves against the zombies, thanks to the equipment Alex shared with you.\n");
                print("After hours of running and hiding, you both reach the main road out of the city.\n");
                print("You see a military checkpoint up ahead, with soldiers stopping all vehicles.\n");
                print("Do you:\n");
                print("1) Try to sneak past the checkpoint.\n");
                print("2) Approach the soldiers and ask for help.\n");
                print("> ");
                cin >> choice;

                if (!cin) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }
                
                if (choice == 1) scene = 8; // Sneak past
                else if (choice == 2) {
                    print("\nYou approach the soldiers, hoping for help.\n");
                    print("However, they see you as a threat and open fire immediately.\n");
                    print("You and Alex are hit and fall to the ground.\n");
                    print(string(YouDied) + "\n");
                    alive = false;
                }
                else print("Invalid choice.\n");
            }
            else print("Invalid choice.\n");
        }

        else if (scene == 7) {
            print("You barely escape the horde of zombies without being noticed.\n");
            print("You run through the dark streets, heart pounding.\n");
            print("As you pass a school, you see a group of survivors getting inside.\n");
            print("Do you:\n");
            print("1) Try to join the group.\n");
            print("2) Keep running and find your own way.\n");
            print("> ");
            cin >> choice;

            if (!cin) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

            if (choice == 1) scene = 9; // Join the group
            else if (choice == 2) scene = 10; // Find your own way
            else {
                print("Invalid choice.\n");
                continue;
            }
        
        }

        // --- Scene 8: Sneak past ---
        else if (scene == 8) {
            print("\nYou and Alex find an old road leading out of the city. It's not under patrol.\n");
            print("You decide to pass through the abandoned road. You're leaving, even if on foot.\n");
            print("You spend all night navigating the dark, overgrown path.\n");
            print("You're miles away, and need to rest for a while. You find an old barn.\n");
            print("You both enter and lay down to rest.\n");
            print("Suddenly, you hear noises outside. Zombies have found you.\n");
            print("You and Alex try to defend yourselves, but there are too many.\n");
            print("Alex pushes you aside. 'Go! I'll hold them off!'\n");
            print("You run out of the barn, hearing Alex's last stand behind you.\n");
            print("You manage to escape, but you lost your only friend in this nightmare.\n");
            print("You are now alone, but alive. You vow to survive, no matter what.\n");
            print("You spend a few days walking towards the next town.\n");
            print("You're out of food and water, and your strength is fading.\n");
            print("Just when you think you can't go on, a car pulls up beside you.\n");
            print("The driver offers you a ride.\n");
            print("You get in, thank the driver, and fall asleep, exhausted but hopeful.\n");
            print("In the neighbouring town, you're watching the news, which reports that the military has contained the outbreak.\n");
            print("Some survivors are being evacuated, and the situation is stabilizing.\n");
            print("Alex really gave you a chance to live. You feel grateful and determined to make it through this.\n");
            print(string(YouLive1) + "\n");
            alive = false;
        }

        // --- Scene 9: Join the group ---
        else if (scene == 9) {
            print("\nYou approach the group of survivors at the school. They look wary but let you in after a brief conversation.\n");
            print("Not everyone is happy to see you, one of the leaders tells you you should earn their trust.\n");
            print("Do you:\n");
            print("1) Try to prove yourself by taking on dangerous tasks, and helping out the group.\n");
            print("2) Play it safe and help with minor chores.\n");
            print("> ");
            cin >> choice;

            if (!cin) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

            if (choice == 1) {
                print("\nYou throw yourself into dangerous tasks, risking your life to prove your worth.\n");
                print("Your bravery earns you the respect of the group, and you become a valued member.\n");
                print("It's only been a few days, but you feel hope towards the future.\n");
                scene = 11; // Last night at the school
                trust = 1; // Gained trust
            }
            else if (choice == 2) {
                print("\nYou decide to play it safe, helping with minor chores and staying out of trouble.\n");
                print("A few days pass, and you finally feel you can sleep without looking over your shoulder.\n");
                scene = 11; // Last night at the school
                trust = 0; // No trust gained
            }
            else {
                print("Invalid choice.\n");
                continue;
            }
        }

        // --- Scene 10: Find your own way ---
        else if (scene == 10) {
            print("\nYou decide not to join the group, preferring to find your own way.\n");
            print("You reach city limits, and an old church that seems untouched by the chaos.\n");
            print("You take refuge inside, hoping for it to be a safe haven.\n");
            print("A few days pass, and you finally feel you can sleep without looking over your shoulder.\n");
            print("But one day, as you cook, you hear voices and radio outside.\n");
            print("They know you're there. Are they friend or foe?\n");
            print("Do you:\n");
            print("1) Hide and wait to see what they do.\n");
            print("2) Don't take any chances and prepare for a fight.\n");
            print("> ");
            cin >> choice;

            if (!cin) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

            if (choice == 1) {
                print("\nYou decide to hide and wait, holding your breath as the voices draw closer.\n");
                print("The steps fade away, and you let out a sigh of relief.\n");
                print("As you listen closely, you hear a helicopter entering the area.\n");
                print("There's a speaker on board, and it's repeating the next message:\n");
                print("\"Attention all survivors, we are here to help. The outbreak is under control.\"\n");
                print("\"The military will not open fire to any surviving civilians.\"\n");
                print("You still have doubts, but it might be really over.\n");
                print("You decide to leave the church and try to find the helicopter.\n");
                print("You reach the city hall, where the helicopter is landing.\n");
                print("You see a group of survivors being evacuated. You join them, hoping for a better future.\n");
                print("As you board the helicopter, you look back at the city, now a shadow of its former self.\n");
                print("You feel a mix of relief and sadness, but also hope for a new beginning.\n");
                print(string(YouLive2) + "\n");
                alive = false;
            }
            else if (choice == 2) {
                print("\nYou hear them approach, your heart races. You grip your weapon, and accidentally make a noise.\n");
                print("The voices stop, they turn directly to the church. This is it.\n");
                print("They shine flashlights into the church, Alex looks at you, nods in fear.\n");
                print("Alex shoots one of them, and chaos erupts.\n");
                print("In the confusion, you manage to take down the group, it's over quickly.\n");
                print("As you catch your breath, you hear an helicopter approaching.\n");
                print("There's a speaker on board, and it's repeating the next message:\n");
                print("\"Attention all survivors, we are here to help. The outbreak is under control.\"\n");
                print("\"The military will not open fire to any surviving civilians.\"\n");
                print("You're both in silence. If that message is true, did you just kill people who were trying to help?\n");
                print("You decide to leave the church and try to find the helicopter.\n");
                print("You reach the city hall, where the helicopter is landing.\n");
                print("You see a group of survivors being evacuated. So it's true, the outbreak is over.\n");
                print("Maybe if you had trusted them, you wouldn't have had to kill.\n");
                print("You join the group, with a bittersweet feeling in your heart.\n");
                print(string(YouLive1) + "\n");
                alive = false;
            }
            else {
                print("Invalid choice.\n");
                continue;
            }
        }

        // --- Scene 11: Last night at the school ---
        else if (scene == 11) {
            print("\nOne night, as you and Alex are on watch, you receive a radio transmission.\n");
            print("It's a distress call from a group that was gathering supplies.\n");
            print("They are being chased by the military, and are about to get to the school.\n");
            print("Everybody is on high alert, knowing the danger is close. You see them approaching.\n");
            print("The military stops as they reach the perimeter of the school. You hear them call reinforcements.\n");
            print("The group is panicking, everyone's fingers are on the triggers.\n");
            print("But the military is not attacking, they are just waiting.\n");
            print("They have more troops and armament, but they are not making a move.\n");
            print("You decide to radio everyone and tell them to stand down and take cover.\n");
            print("Maybe if you show you're not a threat, they will leave.\n");

                if (trust == 1) {
                    print("\nThe other leaders follow your lead and stand down. Everyone takes cover and waits.\n");
                    print("For hours, tension is palpable as you all wait for the military's next move.\n");
                    print("Dawn comes, and you see hesitation and confusion in the military.\n");
                    print("As you wonder why, you hear a helicopter approaching the zone.\n");
                    print("There's a speaker on board, and it's repeating the next message:\n");
                    print("\"Attention all survivors, we are here to help. The outbreak is under control.\"\n");
                    print("\"The military will not open fire to any surviving civilians.\"\n");
                    print("The military lowers their weapons, and after a moment of silence...\n");
                    print("Everyone cheers. The military joins the celebration, and you decide to join them.\n");
                    print("You find the helicopter, it landed on the city hall.\n");
                    print("You see a group of survivors being evacuated. You join them, hopeful for a better future.\n");
                    print("These past days have been hell, but you made it out with Alex and a new group of friends.\n");
                    print("You all share stories of your experiences, finding comfort in each other's company.\n");
                    print(string(YouLive2) + "\n");
                    alive = false;
                } else {
                    print("\nThere's a moment of tension and silence... But it doesn't last long.\n");
                    print("Another leader says, 'We can't wait for them to make the first move!'\n");
                    print("The group takes the first shot, and chaos erupts.\n");
                    print("The military responds with overwhelming force.\n");
                    print("They fire indiscriminately, annihilating everyone in their path.\n");
                    print("You both are not the exception.\n");
                    print(string(YouDied) + "\n");
                    alive = false;
                }
        }
        else {
            print("An error occurred. Exiting game.\n");
            alive = false;
        }
    }

    print("\nThanks for playing Days of Survival.\n");
    return 0;
}

