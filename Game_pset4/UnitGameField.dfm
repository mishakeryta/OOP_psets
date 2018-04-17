object FormGame: TFormGame
  Left = 375
  Top = 185
  BorderStyle = bsDialog
  Caption = 'Game'
  ClientHeight = 287
  ClientWidth = 207
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Label: TLabel
    Left = 43
    Top = 8
    Width = 13
    Height = 21
  end
  object CSpinEdit: TCSpinEdit
    Left = 160
    Top = 8
    Width = 49
    Height = 22
    MaxValue = 7
    TabOrder = 0
  end
  object sgGameField: TStringGrid
    Left = 0
    Top = 32
    Width = 209
    Height = 209
    Cursor = crCross
    Color = clInfoBk
    DefaultColWidth = 40
    DefaultRowHeight = 40
    FixedCols = 0
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssNone
    TabOrder = 1
    OnSelectCell = sgGameFieldSelectCell
  end
  object btStart: TButton
    Left = 0
    Top = 240
    Width = 207
    Height = 25
    Caption = 'Start'
    TabOrder = 2
    OnClick = btStartClick
  end
  object editTime: TEdit
    Left = 0
    Top = 8
    Width = 33
    Height = 21
    Enabled = False
    TabOrder = 3
  end
  object Timer: TTimer
    Enabled = False
    OnTimer = TimerTimer
    Left = 120
    Top = 8
  end
end
