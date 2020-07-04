/*
    This file is part of Helio Workstation.

    Helio is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Helio is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Helio. If not, see <http://www.gnu.org/licenses/>.
*/

#include "Common.h"
#include "MidiTrackMenu.h"
#include "MidiTrackNode.h"
#include "PianoTrackNode.h"

#include "MainLayout.h"
#include "AudioCore.h"
#include "Instrument.h"
#include "MidiSequence.h"
#include "HybridRoll.h"
#include "ProjectNode.h"
#include "ModalDialogInput.h"

#include "MidiSequence.h"
#include "PianoTrackNode.h"
#include "AutomationTrackNode.h"
#include "MidiTrackActions.h"
#include "PianoTrackActions.h"
#include "AutomationTrackActions.h"
#include "UndoStack.h"
#include "Workspace.h"

#include "CommandIDs.h"
#include "ColourIDs.h"
#include "Icons.h"

MidiTrackMenu::MidiTrackMenu(MidiTrackNode &node) :
    trackNode(node)
{
    this->initDefaultMenu();
}

void MidiTrackMenu::initDefaultMenu()
{
    MenuPanel::Menu menu;
    menu.add(MenuItem::item(Icons::selectAll, CommandIDs::SelectAllEvents, TRANS(I18n::Menu::trackSelectall))->closesMenu());
    
    menu.add(MenuItem::item(Icons::ellipsis, CommandIDs::RenameTrack,
        TRANS(I18n::Menu::trackRename))->closesMenu());

    menu.add(MenuItem::item(Icons::copy, CommandIDs::DuplicateTrack,
        TRANS(I18n::Menu::trackDuplicate))->closesMenu());

    menu.add(MenuItem::item(Icons::remove,
        CommandIDs::DeleteTrack, TRANS(I18n::Menu::trackDelete)));

    const auto &instruments = App::Workspace().getAudioCore().getInstruments();
    menu.add(MenuItem::item(Icons::instrument, TRANS(I18n::Menu::trackChangeInstrument))->
        disabledIf(instruments.isEmpty())->withSubmenu()->withAction([this]()
    {
        this->initInstrumentSelectionMenu();
    }));

    const auto trackInstrument = this->trackNode.getTrackInstrumentId();
    for (const auto *i : instruments)
    {
        // well, the track can have an instrument which has no window; but here,
        // in the menu constructor, it's kinda too expensive to check if this is the case,
        // so we'll only show this menu item, if the instrument has been assigned:
        if (i->getIdAndHash() == trackInstrument)
        {
            const auto editInstrumentCaption = i->getName() + ": " + TRANS(I18n::Menu::instrumentShowWindow);
            menu.add(MenuItem::item(Icons::instrument, CommandIDs::EditCurrentInstrument,
                editInstrumentCaption)->disabledIf(trackInstrument.isEmpty())->closesMenu());
            break;
        }
    }

    this->updateContent(menu, MenuPanel::SlideRight);
}

void MidiTrackMenu::initInstrumentSelectionMenu()
{
    MenuPanel::Menu menu;
    menu.add(MenuItem::item(Icons::back, TRANS(I18n::Menu::back))->withAction([this]()
    {
        this->initDefaultMenu();
    }));
    
    const auto &audioCore = App::Workspace().getAudioCore();
    const auto &instruments = audioCore.getInstruments();
    const auto *selectedInstrument = audioCore.findInstrumentById(this->trackNode.getTrackInstrumentId());

    for (int i = 0; i < instruments.size(); ++i)
    {
        const bool isTicked = (instruments[i] == selectedInstrument);
        const String instrumentId = instruments[i]->getIdAndHash();
        menu.add(MenuItem::item(isTicked ? Icons::apply : Icons::instrument,
            instruments[i]->getName())->withAction([this, instrumentId]()
        {
            // no need to check if not toggled, the callback will do
            // DBG(instrumentId);
            this->trackNode.getChangeInstrumentCallback()(instrumentId);
            this->initDefaultMenu();
            return;
        }));
    }
    
    this->updateContent(menu, MenuPanel::SlideLeft);
}
