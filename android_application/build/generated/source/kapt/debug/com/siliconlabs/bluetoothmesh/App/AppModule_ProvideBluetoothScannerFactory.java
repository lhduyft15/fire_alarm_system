// Generated by Dagger (https://google.github.io/dagger).
package com.siliconlabs.bluetoothmesh.App;

import com.siliconlabs.bluetoothmesh.App.Logic.BluetoothScanner;
import com.siliconlabs.bluetoothmesh.App.Logic.BluetoothStateReceiver;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import javax.inject.Provider;

public final class AppModule_ProvideBluetoothScannerFactory implements Factory<BluetoothScanner> {
  private final AppModule module;

  private final Provider<BluetoothStateReceiver> bluetoothStateReceiverProvider;

  public AppModule_ProvideBluetoothScannerFactory(
      AppModule module, Provider<BluetoothStateReceiver> bluetoothStateReceiverProvider) {
    this.module = module;
    this.bluetoothStateReceiverProvider = bluetoothStateReceiverProvider;
  }

  @Override
  public BluetoothScanner get() {
    return provideInstance(module, bluetoothStateReceiverProvider);
  }

  public static BluetoothScanner provideInstance(
      AppModule module, Provider<BluetoothStateReceiver> bluetoothStateReceiverProvider) {
    return proxyProvideBluetoothScanner(module, bluetoothStateReceiverProvider.get());
  }

  public static AppModule_ProvideBluetoothScannerFactory create(
      AppModule module, Provider<BluetoothStateReceiver> bluetoothStateReceiverProvider) {
    return new AppModule_ProvideBluetoothScannerFactory(module, bluetoothStateReceiverProvider);
  }

  public static BluetoothScanner proxyProvideBluetoothScanner(
      AppModule instance, BluetoothStateReceiver bluetoothStateReceiver) {
    return Preconditions.checkNotNull(
        instance.provideBluetoothScanner(bluetoothStateReceiver),
        "Cannot return null from a non-@Nullable @Provides method");
  }
}
