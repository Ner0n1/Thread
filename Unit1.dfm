object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 189
  ClientWidth = 533
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  PixelsPerInch = 96
  TextHeight = 15
  object Label1: TLabel
    Left = 64
    Top = 85
    Width = 59
    Height = 15
    Caption = 'Target disk:'
  end
  object Label3: TLabel
    Left = 160
    Top = 85
    Width = 79
    Height = 15
    Caption = 'Block size (Kb):'
  end
  object Label5: TLabel
    Left = 296
    Top = 85
    Width = 44
    Height = 15
    Caption = 'Block N:'
  end
  object Label6: TLabel
    Left = 360
    Top = 85
    Width = 6
    Height = 15
    Caption = '0'
  end
  object Label8: TLabel
    Left = 406
    Top = 85
    Width = 32
    Height = 15
    Caption = 'Block:'
  end
  object Label10: TLabel
    Left = 464
    Top = 85
    Width = 5
    Height = 15
    Caption = '-'
  end
  object Button1: TButton
    Left = 56
    Top = 17
    Width = 177
    Height = 41
    Caption = 'Start Multi Thread Processing'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 296
    Top = 17
    Width = 177
    Height = 41
    Caption = 'Stop Multi Thread Processing'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Edit1: TEdit
    Left = 160
    Top = 106
    Width = 81
    Height = 23
    NumbersOnly = True
    TabOrder = 2
    Text = '4'
  end
  object Edit2: TEdit
    Left = 64
    Top = 106
    Width = 81
    Height = 23
    TabOrder = 3
    Text = '\\.\C:'
  end
  object Button5: TButton
    Left = 166
    Top = 146
    Width = 75
    Height = 23
    Caption = 'Exit'
    TabOrder = 4
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 64
    Top = 146
    Width = 75
    Height = 23
    Caption = 'Set Default'
    TabOrder = 5
    OnClick = Button6Click
  end
end
