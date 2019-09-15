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
#include "CommandIDs.h"

#define CASE_FOR(x) \
    case constexprHash(#x): \
    return x; \

int CommandIDs::getIdForName(const String &command)
{
    switch (constexprHash(command.toRawUTF8()))
    {
        CASE_FOR(Back)
        CASE_FOR(Cancel)
        CASE_FOR(Browse)
        CASE_FOR(IconButtonPressed)
        CASE_FOR(MenuButtonPressed)
        CASE_FOR(RootTreeItemPressed)
        CASE_FOR(HideDialog)
        CASE_FOR(HideCallout)
        CASE_FOR(DismissModalDialogAsync)
        CASE_FOR(ChangeTimeSignature)
        CASE_FOR(ChangeTimeSignatureConfirmed)
        CASE_FOR(DeleteTimeSignature)
        CASE_FOR(RenameAnnotation)
        CASE_FOR(RenameAnnotationConfirmed)
        CASE_FOR(SetAnnotationColour)
        CASE_FOR(DeleteAnnotation)
        CASE_FOR(AddAnnotation)
        CASE_FOR(AddAnnotationConfirmed)
        CASE_FOR(AddTimeSignature)
        CASE_FOR(AddTimeSignatureConfirmed)
        CASE_FOR(AddKeySignature)
        CASE_FOR(AddKeySignatureConfirmed)
        CASE_FOR(JumpToAnnotation)
        CASE_FOR(CreateArpeggiatorFromSelection)
        CASE_FOR(InitWorkspace)
        CASE_FOR(RenameInstrument)
        CASE_FOR(UpdateInstrument)
        CASE_FOR(DeleteInstrument)
        CASE_FOR(ScanAllPlugins)
        CASE_FOR(ScanPluginsFolder)
        CASE_FOR(DeleteTrack)
        CASE_FOR(RenameTrack)
        CASE_FOR(SelectAllEvents)
        CASE_FOR(SelectAllClips)
        CASE_FOR(NewTrackFromSelection)
        CASE_FOR(Tuplet1)
        CASE_FOR(Tuplet2)
        CASE_FOR(Tuplet3)
        CASE_FOR(Tuplet4)
        CASE_FOR(Tuplet5)
        CASE_FOR(Tuplet6)
        CASE_FOR(Tuplet7)
        CASE_FOR(Tuplet8)
        CASE_FOR(Tuplet9)
        CASE_FOR(DeleteEvents)
        CASE_FOR(CopyEvents)
        CASE_FOR(CutEvents)
        CASE_FOR(PasteEvents)
        CASE_FOR(DeleteClips)
        CASE_FOR(CopyClips)
        CASE_FOR(CutClips)
        CASE_FOR(PasteClips)
        CASE_FOR(EditClip)
        CASE_FOR(ClipTransposeUp)
        CASE_FOR(ClipTransposeDown)
        CASE_FOR(ClipVolumeUp)
        CASE_FOR(ClipVolumeDown)
        CASE_FOR(ToggleMuteClips)
        CASE_FOR(ToggleSoloClips)
        CASE_FOR(ZoomIn)
        CASE_FOR(ZoomOut)
        CASE_FOR(ZoomEntireClip)
        CASE_FOR(Undo)
        CASE_FOR(Redo)
        CASE_FOR(ShowAnnotations)
        CASE_FOR(TimelineJumpNext)
        CASE_FOR(TimelineJumpPrevious)
        CASE_FOR(ResetPreviewChanges)
        CASE_FOR(ApplyOpenGLRenderer)
        CASE_FOR(TransportStartPlayback)
        CASE_FOR(TransportPausePlayback)
        CASE_FOR(PopupMenuDismiss)
        CASE_FOR(PopupMenuDismissedAsDone)
        CASE_FOR(PopupMenuDismissedAsCancel)
        CASE_FOR(SelectRootItemPanel)
        CASE_FOR(DeselectRootItemPanel)
        CASE_FOR(UpdateRootItemPanel)
        CASE_FOR(LoginLogout)
        CASE_FOR(OpenProject)
        CASE_FOR(CreateNewProject)
        CASE_FOR(RenderToFLAC)
        CASE_FOR(RenderToWAV)
        CASE_FOR(AddItemsMenu)
        CASE_FOR(AddItemsMenuBack)
        CASE_FOR(AddMidiTrack)
        CASE_FOR(AddMidiTrackConfirmed)
        CASE_FOR(AddAutomationTrack)
        CASE_FOR(ImportMidi)
        CASE_FOR(ExportMidi)
        CASE_FOR(UnloadProject)
        CASE_FOR(DeleteProject)
        CASE_FOR(DeleteProjectConfirmed1)
        CASE_FOR(DeleteProjectConfirmed2)
        CASE_FOR(ProjectTransposeUp)
        CASE_FOR(ProjectTransposeDown)
        CASE_FOR(ProjectRemoveOverlaps)
        CASE_FOR(ProjectPatternEditor)
        CASE_FOR(ProjectLinearEditor)
        CASE_FOR(ProjectVersionsEditor)
        CASE_FOR(ProjectMainMenu)
        CASE_FOR(ProjectRenderMenu)
        CASE_FOR(ProjectBatchMenu)
        CASE_FOR(ProjectBatchMenuBack)
        CASE_FOR(AddTempoController)
        CASE_FOR(BatchChangeInstrument)
        CASE_FOR(SelectFunction)
        CASE_FOR(SelectScale)
        CASE_FOR(SelectTimeSignature)
        CASE_FOR(SelectVersion)
        CASE_FOR(SwitchBetweenRolls)
        CASE_FOR(SwitchToEditMode)
        CASE_FOR(SwitchToArrangeMode)
        CASE_FOR(SwitchToVersioningMode)
        CASE_FOR(ShowPreviousPage)
        CASE_FOR(ShowNextPage)
        CASE_FOR(ShowRootPage)
        CASE_FOR(ToggleShowHideCombo)
        CASE_FOR(StartDragViewport)
        CASE_FOR(EndDragViewport)
        CASE_FOR(SelectAudioDeviceType)
        CASE_FOR(SelectAudioDevice)
        CASE_FOR(SelectSampleRate)
        CASE_FOR(SelectBufferSize)
        CASE_FOR(SelectFont)
        CASE_FOR(EditModeDefault)
        CASE_FOR(EditModeDraw)
        CASE_FOR(EditModePan)
        CASE_FOR(EditModeSelect)
        CASE_FOR(EditModeKnife)
        CASE_FOR(EditModeEraser)
        CASE_FOR(EditModeChordBuilder)
        CASE_FOR(BeatShiftLeft)
        CASE_FOR(BeatShiftRight)
        CASE_FOR(BarShiftLeft)
        CASE_FOR(BarShiftRight)
        CASE_FOR(KeyShiftUp)
        CASE_FOR(KeyShiftDown)
        CASE_FOR(OctaveShiftUp)
        CASE_FOR(OctaveShiftDown)
        CASE_FOR(CleanupOverlaps)
        CASE_FOR(InvertChordUp)
        CASE_FOR(InvertChordDown)
        CASE_FOR(MelodicInversion)
        CASE_FOR(Retrograde)
        CASE_FOR(ShowArpeggiatorsPanel)
        CASE_FOR(ShowVolumePanel)
        CASE_FOR(ShowRescalePanel)
        CASE_FOR(ShowScalePanel)
        CASE_FOR(ShowChordPanel)
        CASE_FOR(TweakVolumeRandom)
        CASE_FOR(TweakVolumeFadeOut)
        CASE_FOR(VersionControlToggleQuickStash)
        CASE_FOR(VersionControlPushSelected)
        CASE_FOR(VersionControlPullSelected)
        CASE_FOR(VersionControlSyncAll)
        CASE_FOR(VersionControlResetAll)
        CASE_FOR(VersionControlCommitAll)
        CASE_FOR(VersionControlSelectAll)
        CASE_FOR(VersionControlSelectNone)
        CASE_FOR(VersionControlResetSelected)
        CASE_FOR(VersionControlCommitSelected)
        CASE_FOR(VersionControlCheckout)
        CASE_FOR(PatternsGroupByName)
        CASE_FOR(PatternsGroupByColour)
        CASE_FOR(PatternsGroupByInstrument)
        CASE_FOR(PatternsGroupById)
        CASE_FOR(ShowConsole)
        default:
            return 0;
    };
}
