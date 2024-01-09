object DataModule2: TDataModule2
  Height = 750
  Width = 1000
  PixelsPerInch = 120
  object FDConnection1: TFDConnection
    Params.Strings = (
      'DataSource=BDSTUD'
      'DriverID=ODBC')
    Connected = True
    LoginPrompt = False
    Left = 104
    Top = 48
  end
  object FDQuery1: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      'SELECT * FROM STUD')
    Left = 208
    Top = 48
  end
  object DataSource1: TDataSource
    DataSet = FDQuery1
    Left = 304
    Top = 48
  end
  object DataSource2: TDataSource
    DataSet = FDQuery2
    Left = 304
    Top = 144
  end
  object FDQuery2: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      'select * from GRUPA')
    Left = 208
    Top = 144
  end
  object INS_GRUPA: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      'INSERT INTO GRUPA(NUME,AN_FORMARE)'
      'VALUES(:NUME,:AN_FORMARE)')
    Left = 208
    Top = 248
    ParamData = <
      item
        Name = 'NUME'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'AN_FORMARE'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end>
  end
  object DataSource3: TDataSource
    DataSet = INS_GRUPA
    Left = 304
    Top = 248
  end
  object DataSource4: TDataSource
    DataSet = UPD_GRUPA
    Left = 304
    Top = 336
  end
  object UPD_GRUPA: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      'UPDATE GRUPA SET NUME=:NUME,AN_FORMARE=:AN_FORMARE'
      'WHERE GRUPA_ID=:GRUPA_ID;')
    Left = 208
    Top = 336
    ParamData = <
      item
        Name = 'NUME'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'AN_FORMARE'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'GRUPA_ID'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end>
  end
  object DEL_GRUPA: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      'DELETE GRUPA WHERE GRUPA_ID=:GRUPA_ID;')
    Left = 208
    Top = 424
    ParamData = <
      item
        Name = 'GRUPA_ID'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end>
  end
  object DataSource5: TDataSource
    DataSet = DEL_GRUPA
    Left = 304
    Top = 424
  end
  object DataSource6: TDataSource
    DataSet = INS_STUD
    Left = 536
    Top = 264
  end
  object INS_STUD: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      
        'INSERT INTO STUD(NUME,PRENUME,GRUPA_ID,DATA_NAST,GEN,IDNP,TELEFO' +
        'N)'
      'VALUES(:NUME,:PRENUME,:GRUPA_ID,:DATA_NAST,:GEN,:IDNP,:TELEFON)')
    Left = 440
    Top = 248
    ParamData = <
      item
        Name = 'NUME'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'PRENUME'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'GRUPA_ID'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'DATA_NAST'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'GEN'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'IDNP'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'TELEFON'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end>
  end
  object UPD_STUD: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      
        'update STUD set NUME=:NUME,PRENUME=:PRENUME,GRUPA_ID=:GRUPA_ID,D' +
        'ATA_NAST=:DATA_NAST,GEN=:GEN,IDNP=:IDNP,TELEFON=:TELEFON'
      'where STUDENTT_ID=:STUDENTT_ID')
    Left = 440
    Top = 344
    ParamData = <
      item
        Name = 'NUME'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'PRENUME'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'GRUPA_ID'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'DATA_NAST'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'GEN'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'IDNP'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'TELEFON'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'STUDENTT_ID'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end>
  end
  object DEL_STUD: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      'DELETE STUD WHERE STUDENTT_ID=:STUDENTT_ID')
    Left = 440
    Top = 432
    ParamData = <
      item
        Name = 'STUDENTT_ID'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end>
  end
  object DataSource7: TDataSource
    DataSet = UPD_STUD
    Left = 536
    Top = 352
  end
  object DataSource8: TDataSource
    DataSet = DEL_STUD
    Left = 536
    Top = 432
  end
  object Q_AUTENTIFICARE: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      'SELECT *FROM UTILIZATOR WHERE NUME = :NUME AND PAROLA=:PASS')
    Left = 88
    Top = 168
    ParamData = <
      item
        Name = 'NUME'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'PASS'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end>
  end
end
