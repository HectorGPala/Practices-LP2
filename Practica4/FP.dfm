object FormPrincipal: TFormPrincipal
  Left = 347
  Top = 206
  Width = 696
  Height = 480
  Caption = 'EDITOR DE LINEAS'
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
  OnMouseDown = FormMouseDown
  OnMouseMove = FormMouseMove
  OnPaint = FormPaint
  PixelsPerInch = 96
  TextHeight = 13
  object MainMenu1: TMainMenu
    Top = 32
    object Polilinea1: TMenuItem
      Caption = '&Polilinea'
      object Dibujar1: TMenuItem
        Caption = 'Dibujar'
        OnClick = Dibujar1Click
      end
      object EliminarPunto1: TMenuItem
        Caption = 'Eliminar Punto'
        OnClick = EliminarPunto1Click
      end
      object EliminarPolilinea1: TMenuItem
        Caption = 'Eliminar Polilinea'
        OnClick = EliminarPolilinea1Click
      end
      object MoverPunto1: TMenuItem
        Caption = 'Mover Punto'
        OnClick = MoverPunto1Click
      end
    end
    object ColorFondo1: TMenuItem
      Caption = '&Color Fondo'
      OnClick = ColorFondo1Click
    end
    object GrosorLinea1: TMenuItem
      Caption = 'C&olor Actual'
      OnClick = GrosorLinea1Click
    end
    object GrosordeLinea1: TMenuItem
      Caption = '&Grosor de Linea'
      object N11: TMenuItem
        Caption = '1'
        OnClick = N11Click
      end
      object N21: TMenuItem
        Caption = '2'
        OnClick = N21Click
      end
      object N31: TMenuItem
        Caption = '3'
        OnClick = N31Click
      end
    end
    object Archivo1: TMenuItem
      Caption = '&Archivo'
      object Nuevo1: TMenuItem
        Caption = 'Nuevo'
        OnClick = Nuevo1Click
      end
      object Abrir1: TMenuItem
        Caption = 'Abrir'
        OnClick = Abrir1Click
      end
      object Guardar1: TMenuItem
        Caption = 'Guardar'
        OnClick = Guardar1Click
      end
      object GuardarComo1: TMenuItem
        Caption = 'Guardar Como'
        OnClick = GuardarComo1Click
      end
      object Salir1: TMenuItem
        Caption = 'Salir'
        OnClick = Salir1Click
      end
    end
  end
  object ColorDialog: TColorDialog
    Ctl3D = True
    Left = 40
    Top = 32
  end
  object OpenDialog1: TOpenDialog
    Left = 88
    Top = 32
  end
  object SaveDialog1: TSaveDialog
    Left = 136
    Top = 32
  end
end
