object Form1: TForm1
  Left = 296
  Top = 135
  Width = 570
  Height = 631
  Caption = 'Indice'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 216
    Top = 16
    Width = 62
    Height = 29
    Caption = 'Texto'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Memo: TMemo
    Left = 24
    Top = 48
    Width = 505
    Height = 449
    TabOrder = 0
    OnKeyPress = MemoKeyPress
  end
  object MainMenu1: TMainMenu
    Left = 8
    Top = 8
    object IndicedePalabras1: TMenuItem
      Caption = '&Indice de Palabras'
      object Generar1: TMenuItem
        Caption = '&Generar'
        OnClick = Generar1Click
      end
      object Mostrar1: TMenuItem
        Caption = '&Mostrar'
        OnClick = Mostrar1Click
      end
    end
    object Archivo1: TMenuItem
      Caption = '&Archivo'
      object Nuevo2: TMenuItem
        Caption = '&Nuevo'
        OnClick = Nuevo2Click
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object Guardar1: TMenuItem
        Caption = '&Guardar'
        OnClick = Guardar1Click
      end
      object GuardarComo1: TMenuItem
        Caption = 'Guardar &Como'
        OnClick = GuardarComo1Click
      end
      object Cargar1: TMenuItem
        Caption = '&Cargar'
        OnClick = Cargar1Click
      end
    end
    object Filtro1: TMenuItem
      Caption = '&Filtro'
      object Nuevo1: TMenuItem
        Caption = '&Nuevo'
        OnClick = Nuevo1Click
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Aadir1: TMenuItem
        Caption = '&Añadir'
        OnClick = Aadir1Click
      end
      object Eliminar1: TMenuItem
        Caption = '&Eliminar'
        OnClick = Eliminar1Click
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object Guardar: TMenuItem
        Caption = '&Guardar'
        OnClick = GuardarClick
      end
      object GuardarComo: TMenuItem
        Caption = 'Guardar &Como'
        OnClick = GuardarComoClick
      end
      object Cargar2: TMenuItem
        Caption = '&Cargar'
        OnClick = Cargar2Click
      end
    end
    object IndiceGeneral1: TMenuItem
      Caption = 'Indice General'
      object Generar2: TMenuItem
        Caption = 'Generar'
        OnClick = Generar2Click
      end
      object Mostrar2: TMenuItem
        Caption = 'Mostrar'
        OnClick = Mostrar2Click
      end
    end
  end
  object OpenDialog: TOpenDialog
    Left = 48
    Top = 8
  end
  object SaveDialog: TSaveDialog
    Left = 96
    Top = 8
  end
end
