# 環境作成流れ
## Git
* リポジトリ作成(@リモート)

* 指示に従ってローカルでリポジトリ作成，登録，push

* Unity用の .gitignore を add, commit する(途中から .gitignore する場合は然るべき対処をする)
    * 参考: <http://vdeep.net/gitignore>  

* 新しい機能を追加するときはbranch切って，そっちで作業しておく(正常に動く環境をいつでも呼び出せるように)

## Unity
* Unityソフトウェアインストール
    * (hogehoge)
* UnityHubで新規プロジェクト(Unity2019.4.31f1)(3Dプロジェクト)
* VIVEのための環境構築
    >参考：[Qiita(Unity2019でVR開発のための環境を整える)](https://qiita.com/RyoyaHase/items/36910ec8a0b3d8122f8c)
    * (1) UnityXRの有効化(Project Settingsの設定)
        * Edit->Project Settings
        * XR Plugin Management -> Install XR Plugin Management (OpenVRで開発するのでインストール後はチェックマーク入れない)
        * Project Setting -> Player -> Virtual Reality Supportedにチェックを入れる
        * 全部OKして再度チェックマーク入れる
        * 下のSDKにOpenVRを入れる->追加されたらOK
    * (2) Unityパッケージをダウンロード・追加
        * Gitの[SteamVR Unity Plugin Releases](https://github.com/ValveSoftware/steamvr_unity_plugin/releases)でsteamvr_2_7_x.unitypackageをダウンロード
        * Assets->Import Package->Custom Package->さっきの.unitypackageを開く
        * デフォルトでimport->ウインドウをOKで閉じる
        * SteamVRのSettingWindowが出るのでAccept ALLする->アセットにSteamVR関連のフォルダが追加される
        * Project SettingsのXR-Plugin ManagementのOpenVR Loaderにチェックが入っているか確認
            * 上記でダメだった場合：Project Settings->Player->XR Setting->Virtual Reality Supportedのチェックを外す->ウインドウが出るのでUnityXRを選択
            * 再起動した方が良いと言われるので再起動する
            * ->再度Virtual Reality Supportedにチェックを入れる->Project Settings/XR Plug-in Management/OpenoVR Loaderにチェックがついているか確認
        * 念のためSaveしてプロジェクトを開きなおす
    * (x) SteamVR Pluginのimport
        * UnityのAsset Storeから[SteamVR Plugin](https://assetstore.unity.com/packages/tools/integration/steamvr-plugin-32647)をimport
        * 再起動
    * (3) 動作確認
        * プロジェクトタブのSteamVRフォルダ内のSimple Sampleシーンを開く
        * SteamVR(紺色の小さいウインドウ)を起動して，ヘッドセットとコントローラ，ベースステーションを認識させる
        * 実行
            * (初回起動時のみ)
            * コントローラの入力を得るためにSteamVR Inputを開く必要があるので「Yes」を押す
            * コントローラの入力方式と，ボタン等の設定一覧が表示される
            * Save and generateを押してウインドウを閉じる
            * 実行しなおしてコントローラが正しく認識されていればOK
    * (4) サンプルプログラムを動かす
        * SteamVR/InteractionSystem/Sample/Interactions_Exampleを触ってみる
* シリアル通信のための環境設定
    * Project Settings/Player/Api Compatibility Level* を.NET 4.xに変更する

* オブジェクトファイル準備
    * 翼オブジェクト
        * [Clara.io(angel wings)](https://clara.io/view/94bb2ae9-da6c-4d0d-9d06-b43af66d27b4)
        * Assets以下にファイルを作り，.objと.mtlファイル両方をドラッグ&ドロップする
    * terrainオブジェクト
        * [ZENRIN City Asset Series(Unity向け3D都市モデルデータ)](https://www.zenrin.co.jp/contents/product/service/3d/asset/index.html)
            * Japanese Otaku Cityを使用中
        * Unity Asset StoreよりImport
    * ヒト型オブジェクト
        * [Unity-Chan](https://unity-chan.com/)
        * 公式サイトから.unitypackageをダウンロードしてImport
* Scripts準備
    * 過去に作ったやつをそのままコピペ(metaFileごと持ってきて良い)

# Scene作成
## 基本的な部分
* skybox(背景)の変更
    * 現在はZRNAssets/Skyboxes内のSkyboxを使用中
* Terrain設置と衝突判定
    * Assets/ZRNAssets/005339_08932_25_14/Models/PQ_Remake_AKIHABARAを使用中
        * PQ_Remake_AKIHABARA/PQ_GroundにMeshColliderコンポーネントをアタッチ
* ヒトオブジェクトと翼オブジェクトの準備
    * HierarchyでCreate Emptyを行い，そこにオブジェクトを入れていく
    * ヒトオブジェクト
        * Assets/UnityChan/Models/BoxUnityChanを使用中
        * BoxUnityChanにRigidbodyとBoxColliderコンポーネントをアタッチ 
        * カメラの位置を顔の場所に設置
    * 翼オブジェクト
        * VirtualWingsをいい感じの場所に設置(この部分は手作業なのでもっと簡略化したい)
    * それぞれの相対位置
        * hoge

* Serial通信準備
    * Create Emptyで空オブジェクトを作り，SerialHandlerとリネーム
    * SerialHandler.csファイルをアタッチ


編集途中
* VirtualWingsオブジェクトにFollowCanera.cs, PlayerMoveByxxx.csをアタッチする


    

## 2D環境
* 内容
    * hoge
## 3D(VR)環境
* 内容
    * fuga
## テスト環境
* 


# Unityで使っていること
* from overleaf
* hogehoge

# その他
* 衝突判定について
    * > [(Qiita) UnityのRigidbodyとColliderで衝突判定](https://qiita.com/yando/items/0cd2daaf1314c0674bbe)
        * 衝突判定を生む条件 
            * 落下する物体
                * 物体の形に応じた Collider
                * 重力が設定された Rigidbody
            * 受け止める地面
                * 地面の形に応じた Collider
    
* Markdownファイルについて
    * 書き方  
        >[(Qiita) Markdown記法一覧](https://qiita.com/oreo/items/82183bfbaac69971917f)
    * プレビューの仕方  
        VScodeの機能(サイドバイサイドにプレビュー表示)：[Ctrl] + [K] → [V]

