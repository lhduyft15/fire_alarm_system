// Generated by Dagger (https://google.github.io/dagger).
package com.siliconlabs.bluetoothmesh.App.Fragments.MainFragment;

import com.siliconlabs.bluetoothmesh.App.Logic.BluetoothStateReceiver;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import javax.inject.Provider;

public final class MainFragmentModule_ProvideMainFragmentPresenterFactory
    implements Factory<MainFragmentPresenter> {
  private final MainFragmentModule module;

  private final Provider<MainFragmentView> mainFragmentViewProvider;

  private final Provider<BluetoothStateReceiver> bluetoothStateReceiverProvider;

  public MainFragmentModule_ProvideMainFragmentPresenterFactory(
      MainFragmentModule module,
      Provider<MainFragmentView> mainFragmentViewProvider,
      Provider<BluetoothStateReceiver> bluetoothStateReceiverProvider) {
    this.module = module;
    this.mainFragmentViewProvider = mainFragmentViewProvider;
    this.bluetoothStateReceiverProvider = bluetoothStateReceiverProvider;
  }

  @Override
  public MainFragmentPresenter get() {
    return provideInstance(module, mainFragmentViewProvider, bluetoothStateReceiverProvider);
  }

  public static MainFragmentPresenter provideInstance(
      MainFragmentModule module,
      Provider<MainFragmentView> mainFragmentViewProvider,
      Provider<BluetoothStateReceiver> bluetoothStateReceiverProvider) {
    return proxyProvideMainFragmentPresenter(
        module, mainFragmentViewProvider.get(), bluetoothStateReceiverProvider.get());
  }

  public static MainFragmentModule_ProvideMainFragmentPresenterFactory create(
      MainFragmentModule module,
      Provider<MainFragmentView> mainFragmentViewProvider,
      Provider<BluetoothStateReceiver> bluetoothStateReceiverProvider) {
    return new MainFragmentModule_ProvideMainFragmentPresenterFactory(
        module, mainFragmentViewProvider, bluetoothStateReceiverProvider);
  }

  public static MainFragmentPresenter proxyProvideMainFragmentPresenter(
      MainFragmentModule instance,
      MainFragmentView mainFragmentView,
      BluetoothStateReceiver bluetoothStateReceiver) {
    return Preconditions.checkNotNull(
        instance.provideMainFragmentPresenter(mainFragmentView, bluetoothStateReceiver),
        "Cannot return null from a non-@Nullable @Provides method");
  }
}
