# Netrunner Card Finder
### C++ Hack Sprint ~ Spring 2024

**Netrunner Card Finder** is a compact tool created in C++ using the Qt framework that utilizes information from the card information [API](https://api-preview.netrunnerdb.com/) provided by [NetrunnerDB](https://netrunnerdb.com/) to filter Netrunner cards by **name**, **side**, **faction**, and/or **type**. Once the desired filters have been applied, a list of matching cards is displayed, any of the items of which may be selected to display the corresponding images related to that card's possible various printings.

> Learn more about Netrunner @ [BGG](https://boardgamegeek.com/boardgame/124742/android-netrunner) or [Null Signal Games](https://nullsignal.games/about/netrunner/). *Android: Netrunner* is a trademark of Fantasy Flight Games (FFG) and is based on the original *Netrunner* card game created by Richard Garfield and produced by Wizards of the Coast (WotC).
#
### Features:
- Availability of cards ranging from those published officially by FFG beginning in 2012 up to the compatible cards published to this day (Spring 2024) by Null Signal Games.
- Possibility to operate completely disconnected from the internet.
- Fast card search capability made possible by `simdjson`.
- Dynamic search bar reacts to user input on the go.
- Drop-down boxes available to further filter cards by side, faction, or type.
- Clear images displayed tidily in a grid.
- Simple compilation and launch steps.
#
### Requirements:
- `GNU Make`
- `CMake 3.5+`
- `Qt5/Qt6`
- `libcurl`
- `simdjson` (included)
- Reasonably up-to-date version of `GCC` - compiled and tested with v13.2.1 (release 20230801)

Confirmed supported only under `GNU/Linux` OS at this time.

If using `image_grabber.py` to download `cards.json` data or card images:
- `Python 3.11+` with `json`, `pathlib`, `socket`, and `urllib` libraries
#
### Easy compilation with CMake:
Navigate to repository root directory and run the following commands:
```
cmake -S ./ -B nrcf
make -C nrcf
```
Run executable by entering the following command:
```
./ncrf/netrunner_card_finder
```
OR locate the executable file within preferred file explorer GUI at above location (`./` being the root of the repository) and launch.

If necessary, `image_grabber.py` may be used to obtain or update `cards.json` data and/or card images:
```
chmod -v 744 image_grabber.py
./image_grabber.py > image_dl_log.txt 2>&1
```
- If updating `cards.json`, be sure to rename, backup/move, or delete the existing `cards.json` file.
#
### Possible future improvements:
- Reduce any remaining redundancies.
- Improve card image grid layout to better support the possible release of new printings of already existing cards.
- Complete local API storage for more efficient and rapid search operation.
- Add data and statistics information for each card inline, as a tooltip, or in a new window, etc.
- Add more error handling.
#
### Known issues:
- Complete search reset is slower than ideal (see comments in source).
